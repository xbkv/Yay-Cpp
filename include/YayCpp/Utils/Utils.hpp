#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <filesystem>
#include <chrono>
#include <regex>
#include <map>
#include <ctime>
#include <any>
#include <YayCpp/Utils/Models.hpp>
#include <YayCpp/Utils/Constants.hpp>
#include <YayCpp/Utils/Errors.hpp>
#include <YayCpp/Utils/Logger.hpp>
#include <openssl/md5.h>

std::pair<std::string, std::string> getFilenameAndExtension(const std::string& filePath);
bool isValidImageFormat(const std::string& extension);
std::string getHashedFilename(const Attachment& att, const std::string& type, int key, const std::string& uuid);
std::string mention(int userId, const std::string& displayName);
std::vector<MessageTag> buildMessageTags(const std::string& text);
std::string getPostType(const std::map<std::string, std::any>& options);
std::string md5(const std::string& uuid, std::time_t timestamp, bool requireSharedKey);
std::string sha256();

#endif
