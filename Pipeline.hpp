#pragma once

#include "Device.hpp"

// std
#include <string>
#include <vector>

namespace Engine {

    struct PipelineConfigInfo {
        PipelineConfigInfo(const PipelineConfigInfo&) = delete;
        PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

        vk::Viewport viewport;
        vk::Rect2D scissor;
        vk::PipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        vk::PipelineRasterizationStateCreateInfo rasterizationInfo;
        vk::PipelineMultisampleStateCreateInfo multisampleInfo;
        vk::PipelineColorBlendAttachmentState colorBlendAttachment;
        vk::PipelineColorBlendStateCreateInfo colorBlendInfo;
        vk::PipelineDepthStencilStateCreateInfo depthStencilInfo;
        vk::PipelineLayout pipelineLayout = nullptr;
        vk::RenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    class Pipeline {
        public:
        Pipeline(
            Device& device,
            const std::string& vertFilepath,
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);
        ~Pipeline();

        Pipeline(const Pipeline&) = delete;
        Pipeline &operator=(const Pipeline&) = delete;

        void bind(vk::CommandBuffer commandBuffer);

        static void defaultPipelineConfigInfo(
            PipelineConfigInfo& configInfo, uint32_t width, uint32_t height);

        private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(
            const std::string& vertFilepath,
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, vk::ShaderModule* shaderModule);

        Device& device;
        vk::Pipeline graphicsPipeline;
        vk::ShaderModule vertShaderModule;
        vk::ShaderModule fragShaderModule;
    };
}