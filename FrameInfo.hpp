#pragma once

#include "Camera.hpp"

#include <vulkan/vulkan.hpp>

namespace Engine {
    struct FrameInfo {
        int frameIndex;
        float frameTime;
        vk::CommandBuffer commandBuffer;
        Camera &camera;
    };
}