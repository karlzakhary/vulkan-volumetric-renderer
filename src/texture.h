#pragma once

#include <vulkan/vulkan.h>

#include <stdexcept>
#include <string>

#include "buffer.h"
#include "core.h"

class Texture {
public:
    Texture(Core core, std::string imagePath, VkFormat format);
    Texture(Core core, uint32_t width, uint32_t height, VkFormat format);
    Texture& CreateImageView();
    Texture& CreateImageSampler();
    VkImage GetImage() { return image; };
    VkImageView GetImageView() { return imageView; };
    VkSampler GetSampler() { return sampler; }
    void Cleanup();

private:
    Core core;
    VkImage image = VK_NULL_HANDLE;
    VkDeviceMemory textureImageMemory = VK_NULL_HANDLE;
    VkImageView imageView = VK_NULL_HANDLE;
    VkSampler sampler = VK_NULL_HANDLE;
    VkFormat format;

    void CreateImage(uint32_t width, uint32_t height, VkFormat format,
                     VkImageTiling tiling, VkImageUsageFlags usage,
                     VkMemoryPropertyFlags properties, VkImage& image,
                     VkDeviceMemory& imageMemory);

    void TransitionImageLayout(VkImage image, VkFormat format,
                               VkImageLayout oldLayout,
                               VkImageLayout newLayout);
    void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
                           uint32_t height);
};
