#pragma once

#include <string>

struct FilePath {
    inline const static std::string computeShaderPath{ "./shaders/volumetric_comp.spv" };
    inline const static std::string vertexShaderPath{ "./shaders/volumetric_vert.spv" };
    inline const static std::string fragmentShaderPath{ "./shaders/volumetric_frag.spv" };
    inline const static std::string causticTexturePath{"./textures/proceduralCaustics.png"};
};
