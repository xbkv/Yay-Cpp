#include <YayCpp/Utils/Utils.hpp>

namespace fs = std::filesystem;

std::pair<std::string, std::string> getFilenameAndExtension(const std::string& filePath) {
    std::string filename = fs::path(filePath).filename();
    std::string extension = fs::path(filePath).extension();
    return {filename, extension};
}

bool isValidImageFormat(const std::string& extension) {
    static const std::regex imageFormatRegex("\\.(jpg|jpeg|png|gif)$");
    return std::regex_match(extension, imageFormatRegex);
}

std::string getHashedFilename(const Attachment& att, const std::string& type, int key, const std::string& uuid) {
    return "";
}

std::string mention(int userId, const std::string& displayName) {
    if (displayName.empty()) {
        throw YCPError("displayNameは空白にできません。");
    }
    return "<@>" + std::to_string(userId) + ":@" + displayName + "<@/>";
}

std::vector<MessageTag> buildMessageTags(const std::string& text) {
    std::vector<MessageTag> messageTags;
    static const std::regex tagRegex("<@>(\\d+):([^<]+)<@\\/>");
    std::smatch match;
    std::string::const_iterator searchStart(text.cbegin());
    while (std::regex_search(searchStart, text.cend(), match, tagRegex)) {
        int userId = std::stoi(match[1].str());
        std::string displayName = match[2].str();
        size_t offset = match.position();
        size_t length = match.length();
        messageTags.push_back({ length, offset, "user", userId });
        searchStart = match.suffix().first;
    }
    return messageTags;
}

// 投稿タイプを取得する関数
std::string getPostType(const std::map<std::string, std::any>& options) {
    if (options.find("choices") != options.end()) {
        return "survey";
    } else if (options.find("sharedUrl") != options.end()) {
        return "shareable_url";
    } else if (options.find("videoFileName") != options.end()) {
        return "video";
    } else if (options.find("attachmentFileName") != options.end()) {
        return "image";
    } else {
        return "text";
    }
}

// MD5ハッシュを計算する関数
std::string md5(const std::string& uuid, std::time_t timestamp, bool requireSharedKey) {
    std::string sharedKey = requireSharedKey ? SHARED_KEY : "";
    std::string message = API_KEY + uuid + std::to_string(timestamp) + sharedKey;
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(message.c_str()), message.length(), digest);
    char md5String[2 * MD5_DIGEST_LENGTH + 1];
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&md5String[2 * i], "%02x", static_cast<unsigned int>(digest[i]));
    }
    return std::string(md5String);
}

// SHA256ハッシュを計算する関数
std::string sha256() {
    std::string message = "yay_android/" + API_VERSION_NAME;
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(message.c_str()), message.length(), digest);
    return std::string(reinterpret_cast<char*>(digest), SHA256_DIGEST_LENGTH);
}
