#
# Copyright © 2017 Arm Ltd. All rights reserved.
# SPDX-License-Identifier: MIT
#

list(APPEND armnnBackendsCommonUnitTests_sources
    ActivationFixture.hpp
    ActivationTestImpl.hpp
    BackendIdTests.cpp
    BackendRegistryTests.cpp
    BatchNormTestImpl.hpp
    Conv2dTestImpl.hpp
    ConvertFp16ToFp32TestImpl.hpp
    ConvertFp32ToFp16TestImpl.hpp
    EndToEndTestImpl.hpp
    FullyConnectedTestImpl.hpp
    IsLayerSupportedTestImpl.hpp
    JsonPrinterTestImpl.hpp
    LayerReleaseConstantDataTest.cpp
    LayerTests.cpp
    LayerTests.hpp
    LstmTestImpl.hpp
    NormTestImpl.hpp
    OptimizedNetworkTests.cpp
    PermuteTestImpl.hpp
    Pooling2dTestImpl.hpp
    QuantizeHelper.hpp
    ReshapeTestImpl.hpp
    RuntimeTestImpl.hpp
    SoftmaxTestImpl.hpp
    SplitterTestImpl.hpp
    TensorCopyUtils.cpp
    TensorCopyUtils.hpp
    WorkloadDataValidation.cpp
    WorkloadFactoryHelper.hpp
    WorkloadTestUtils.hpp
)

add_library(armnnBackendsCommonUnitTests OBJECT ${armnnBackendsCommonUnitTests_sources})
target_include_directories(armnnBackendsCommonUnitTests PRIVATE ${PROJECT_SOURCE_DIR}/src/armnn)
target_include_directories(armnnBackendsCommonUnitTests PRIVATE ${PROJECT_SOURCE_DIR}/src/armnnUtils)
target_include_directories(armnnBackendsCommonUnitTests PRIVATE ${PROJECT_SOURCE_DIR}/src/backends)