# Arm NN

For more information about Arm NN, see: <https://developer.arm.com/products/processors/machine-learning/arm-nn>

There is a getting started guide here using TensorFlow: <https://developer.arm.com/technologies/machine-learning-on-arm/developer-material/how-to-guides/configuring-the-arm-nn-sdk-build-environment-for-tensorflow>

There is a getting started guide here using TensorFlow Lite: <https://developer.arm.com/technologies/machine-learning-on-arm/developer-material/how-to-guides/configuring-the-arm-nn-sdk-build-environment-for-tensorflow-lite>

There is a getting started guide here using Caffe: <https://developer.arm.com/technologies/machine-learning-on-arm/developer-material/how-to-guides/configuring-the-arm-nn-sdk-build-environment-for-caffe>

There is a getting started guide here using ONNX: <https://developer.arm.com/technologies/machine-learning-on-arm/developer-material/how-to-guides/configuring-the-arm-nn-sdk-build-environment-for-onnx>

There is a guide for backend development: [Backend development guide](src/backends/README.md)

### Build Instructions

Arm tests the build system of Arm NN with the following build environments:

* Android NDK: [How to use Android NDK to build ArmNN](BuildGuideAndroidNDK.md)
* Cross compilation from x86_64 Ubuntu to arm64 Linux: [ArmNN Cross Compilation](BuildGuideCrossCompilation.md)
* Native compilation under arm64 Debian 9

Arm NN is written using portable C++14 and the build system uses [CMake](https://cmake.org/) so it is possible to build for a wide variety of target platforms, from a wide variety of host environments.

The armnn/tests directory contains tests used during ArmNN development. Many of them depend on third-party IP, model protobufs and image files not distributed with ArmNN. The dependencies of some of the tests are available freely on the Internet, for those who wish to experiment.

The 'ExecuteNetwork' program, in armnn/tests/ExecuteNetwork, has no additional dependencies beyond those required by ArmNN and the model parsers. It takes any model and any input tensor, and simply prints out the output tensor. Run with no arguments to see command-line help.

The 'armnn/samples' directory contains SimpleSample.cpp. A very basic example of the ArmNN SDK API in use.

Note that Arm NN needs to be built against a particular version of ARM's Compute Library. The get_compute_library.sh in the scripts subdirectory will clone the compute library from the review.mlplatform.org github repository into a directory alongside armnn named 'clframework' and checkouts the correct revision

### License

Arm NN is provided under the [MIT](https://spdx.org/licenses/MIT.html) license.
See [LICENSE](LICENSE) for more information. Contributions to this project are accepted under the same license.

Individual files contain the following tag instead of the full license text.

    SPDX-License-Identifier: MIT

This enables machine processing of license information based on the SPDX License Identifiers that are available here: http://spdx.org/licenses/