
int main()
{
    VkResult result;

    VkInstanceCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pNext = nullptr;
    createInfo.flags = 0;
    createInfo.pApplicationInfo = nullptr; // a well-behaved application should fill this in with something useful
    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = nullptr;
    createInfo.enabledExtensionCount = 0;
    createInfo.ppEnabledExtensionNames = nullptr;

    result = vkCreateInstance(&createInfo, nullptr, &m_instance);

    if (result == VK_SUCCESS)
    {
        uint32_t physicalDeviceCount = 0;
        result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceCount, nullptr);

        if (result == VK_SUCCESS)
        {
            m_physicalDevices.resize(physicalDeviceCount);
            result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceCount, &m_physicalDevices[0]);

            if (result == VK_SUCCESS)
            {
                VkPhysicalDeviceProperties properties;
                // device features

                for (VkPhysicalDevice physicalDevice : m_physicalDevices)
                {
                    vkGetPhysicalDeviceProperties(physicalDevice, &properties);
                    // device features

                    // print properties & features
                }
            }
        }
    }

    return 0;
}