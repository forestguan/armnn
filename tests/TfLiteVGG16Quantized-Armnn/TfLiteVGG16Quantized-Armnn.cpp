//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include "../InferenceTest.hpp"
#include "../ImagePreprocessor.hpp"
#include "armnnTfLiteParser/ITfLiteParser.hpp"

using namespace armnnTfLiteParser;

int main(int argc, char* argv[])
{
    int retVal = EXIT_FAILURE;
    try
    {
        // Coverity fix: The following code may throw an exception of type std::length_error.
        std::vector<ImageSet> imageSet =
        {
            // The model we are using incorrectly classifies everything as class 699
            // But can still be used for benchmarking the layers.
            {"Dog.jpg", 669},
            {"Cat.jpg", 669},
            {"shark.jpg", 669},
        };

        armnn::TensorShape inputTensorShape({ 2, 224, 224, 3 });

        using DataType = uint8_t;
        using DatabaseType = ImagePreprocessor<DataType>;
        using ParserType = armnnTfLiteParser::ITfLiteParser;
        using ModelType = InferenceModel<ParserType, DataType>;

        // Coverity fix: ClassifierInferenceTestMain() may throw uncaught exceptions.
        retVal = armnn::test::ClassifierInferenceTestMain<DatabaseType,
                                                          ParserType>(
                     argc, argv,
                     "vgg_16_u8.tflite",                  // model name
                     true,                                // model is binary
                     "content_vgg/concat",                // input tensor name
                     "content_vgg/prob",                  // output tensor name
                     { 0, 1, 2 },                         // test images to test with as above
                     [&imageSet](const char* dataDir, const ModelType & model) {
                         // we need to get the input quantization parameters from
                         // the parsed model
                         auto inputBinding = model.GetInputBindingInfo();
                         return DatabaseType(
                             dataDir,
                             224,
                             224,
                             imageSet,
                             inputBinding.second.GetQuantizationScale(),
                             inputBinding.second.GetQuantizationOffset(),
                             {{0, 0, 0}},
                             {{1, 1, 1}},
                             DatabaseType::DataFormat::NCHW,
                             2);
                     },
                     &inputTensorShape);
    }
    catch (const std::exception& e)
    {
        // Coverity fix: BOOST_LOG_TRIVIAL (typically used to report errors) may throw an
        // exception of type std::length_error.
        // Using stderr instead in this context as there is no point in nesting try-catch blocks here.
        std::cerr << "WARNING: " << *argv << ": An error has occurred when running "
                     "the classifier inference tests: " << e.what() << std::endl;
    }
    return retVal;
}
