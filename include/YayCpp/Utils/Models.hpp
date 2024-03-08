#ifndef MODELS_H
#define MODELS_H

#include <iostream>
#include <string>
#include <vector>
#include <optional>

struct Attachment
{
    std::vector<char> Buffer;
    std::string fileName;
    std::string originalFileName;
    std::string originalExtension;
    int naturalWidth;
    bool isThumb;
};

struct User {
    std::optional<bool> ageVerified;
    std::optional<std::string> biography;
    std::optional<bool> chatRequest;
    std::optional<std::vector<std::string>> connectedBy;
    std::optional<std::vector<std::string>> contactPhones;
    std::optional<std::string> countryCode;
    std::optional<std::string> coverImage;
    std::optional<std::string> coverImageThumbnail;
    std::optional<int64_t> createdAt;
    std::optional<bool> dangerousUser;
    std::optional<bool> followPending;
    std::optional<bool> followedBy;
    std::optional<int> followersCount;
    std::optional<bool> following;
    std::optional<int> followingsCount;
    std::optional<bool> fromDifferentGenerationAndTrusted;
    std::optional<int> gender;
    std::optional<int> generation;
    std::optional<GroupUser> groupUser;
    std::optional<int> groupsUsersCount;
    std::optional<bool> hidden;
    std::optional<bool> hideVip;
    int id;
    std::optional<bool> interestsSelected;
    std::optional<bool> isPrivate;
    std::optional<int64_t> lastLoggedinAt;
    std::optional<int> loginStreakCount;
    std::optional<std::string> mobileNumber;
    std::optional<bool> newUser;
    std::optional<std::string> nickname;
    std::optional<std::string> onlineStatus;
    std::optional<int> postsCount;
    std::optional<std::string> prefecture;
    std::optional<std::string> profileIcon;
    std::optional<std::string> profileIconThumbnail;
    std::optional<bool> recentlyKenta;
    std::optional<std::string> restrictedReviewBy;
    std::optional<int> reviewsCount;
    std::optional<std::string> title;
    std::optional<int64_t> updatedTime;
    std::optional<std::string> username;
    bool vip;
};

struct GiftingAbility {
    std::optional<bool> canReceive;
    std::optional<bool> canSend;
    bool enabled;
    std::optional<int> userId;
};

struct GroupUser {
    User user;
    bool isModerator;
    bool pendingTransfer;
    bool pendingDeputize;
    std::string title;
};

struct BumpParams
{
    int participantLimit;
};

struct ConferenceCallUserRole
{
    std::optional<int64_t> number;
    std::string role;
    std::optional<int64_t> userId;
};

struct PlatformDetails {
    std::optional<std::string> affiliateUrl;
    std::string packageId;
};

struct Game {
    std::string iconUrl;
    int id;
    std::optional<PlatformDetails> platformDetails;
    std::string title;
};

struct Genre {
    std::string iconUrl;
    int id;
    std::string title;
};

struct ConferenceCall {
    std::optional<bool> active;
    std::optional<std::string> agoraChannel;
    std::optional<std::string> agoraToken;
    std::optional<int> anonymousCallUsersCount;
    std::optional<BumpParams> bumpParams;
    std::optional<std::string> callType;
    std::vector<ConferenceCallUserRole> conferenceCallUserRoles;
    std::vector<User> conferenceCallUsers;
    std::optional<int> conferenceCallUsersCount;
    std::optional<int> duration;
    std::optional<Game> game;
    std::optional<Genre> genre;
    std::optional<int> groupId;
    int id;
    std::optional<std::string> joinableBy;
    std::optional<int> maxParticipants;
    std::optional<int> postId;
    std::optional<std::string> server;
};

struct Group {
    std::optional<bool> allowMembersToPostImageAndVideo;
    std::optional<bool> allowMembersToPostUrl;
    std::optional<bool> allowOwnershipTransfer;
    std::optional<std::string> allowThreadCreationBy;
    std::optional<bool> callTimelineDisplay;
    std::optional<std::string> coverImage;
    std::optional<std::string> coverImageThumbnail;
    std::optional<std::string> description;
    std::optional<int> gender;
    std::optional<int> generationGroupsLimit;
    std::optional<int> groupCategoryId;
    std::optional<std::string> groupIcon;
    std::optional<std::string> groupIconThumbnail;
    std::optional<int> groupsUsersCount;
    std::optional<std::string> guidelines;
    std::optional<bool> hideConferenceCall;
    std::optional<bool> hideFromGameEight;
    std::optional<bool> hideReportedPosts;
    std::optional<int> highlightedCount;
    int id;
    std::optional<bool> invitedToJoin;
    std::optional<bool> isJoined;
    std::optional<bool> isPending;
    std::optional<bool> isPrivate;
    std::optional<bool> isRelated;
    std::vector<int> moderatorIds;
    std::optional<bool> onlyMobileVerified;
    std::optional<bool> onlyVerifiedAge;
    std::optional<User> owner;
    std::optional<int> pendingCount;
    std::vector<int> pendingDeputizeIds;
    std::optional<int> pendingTransferId;
    std::optional<int> postsCount;
    std::optional<int> relatedCount;
    std::optional<bool> safeMode;
    std::optional<bool> secret;
    std::optional<bool> seizable;
    std::optional<int> seizableBefore;
    std::optional<int> subCategoryId;
    std::optional<int> threadsCount;
    std::optional<std::string> title;
    std::optional<std::string> topic;
    std::optional<int> unreadCounts;
    std::optional<int> unreadThreadsCount;
    std::optional<int> updatedAt;
    std::optional<int> userId;
    std::optional<int> viewsCount;
    std::optional<bool> walkthroughRequested;
};

struct Shareable {
    std::optional<Group> group;
    std::optional<Post> post;
    std::optional<ThreadInfo> thread;
};

struct SharedUrl {
    std::optional<std::string> description;
    std::optional<std::string> imageUrl;
    std::optional<std::string> title;
    std::string url;
};

struct Survey {
    std::vector<Choice> choices;
    int id;
    std::optional<bool> voted;
    std::optional<int> votesCount;
};

struct Choice
{
    int id;
    std::string label;
    std::optional<int> votesCount;
};

struct Video {
    std::optional<int> bitrate;
    std::optional<bool> completed;
    std::optional<int> height;
    int id;
    std::optional<std::string> thumbnailBigUrl;
    std::optional<std::string> thumbnailUrl;
    std::optional<std::string> videoUrl;
    std::optional<int> viewsCount;
    std::optional<int> width;
};

struct GiftCount {
    int id;
    std::optional<int> quantity;
};

struct ThreadInfo {
    std::optional<int> createdAt;
    int id;
    std::optional<bool> isJoined;
    std::optional<Post> lastPost;
    std::optional<bool> newUpdates;
    std::optional<User> owner;
    std::optional<int> postsCount;
    std::optional<std::string> threadIcon;
    std::string title;
    std::optional<int> unreadCount;
    std::optional<int> updatedAt;
};

struct MessageTag {
    std::optional<int> length;
    std::optional<int> offset;
    std::string type;
    std::optional<int> userId;
};

struct Post {
    std::optional<int> id;
    std::optional<std::string> text;
    std::optional<std::string> postType;
    std::optional<int> groupId;
    std::optional<int> fontSize;
    std::optional<int> color;
    std::optional<int> likesCount;
    std::optional<int> createdAt;
    std::optional<int> updatedAt;
    std::optional<int> editedAt;
    std::optional<bool> liked;
    std::vector<User> likers;
    std::optional<std::string> tag;
    std::optional<int> likersCount;
    std::optional<int> repostsCount;
    std::optional<bool> reposted;
    std::optional<bool> repostable;
    std::optional<int> reportedCount;
    std::optional<int> conversationId;
    std::optional<int> inReplyTo;
    std::optional<Post> inReplyToPost;
    std::optional<int> inReplyToPostCount;
    std::optional<User> user;
    std::vector<User> mentions;
    std::optional<Group> group;
    std::optional<ConferenceCall> conferenceCall;
    std::optional<std::string> attachment;
    std::optional<std::string> attachmentThumbnail;
    std::optional<std::string> attachment_2;
    std::optional<std::string> attachment_2Thumbnail;
    std::optional<std::string> attachment_3;
    std::optional<std::string> attachment_3Thumbnail;
    std::optional<std::string> attachment_4;
    std::optional<std::string> attachment_4Thumbnail;
    std::optional<std::string> attachment_5;
    std::optional<std::string> attachment_5Thumbnail;
    std::optional<std::string> attachment_6;
    std::optional<std::string> attachment_6Thumbnail;
    std::optional<std::string> attachment_7;
    std::optional<std::string> attachment_7Thumbnail;
    std::optional<std::string> attachment_8;
    std::optional<std::string> attachment_8Thumbnail;
    std::optional<std::string> attachment_9;
    std::optional<std::string> attachment_9Thumbnail;
    std::optional<Shareable> shareable;
    std::optional<SharedUrl> sharedUrl;
    std::optional<Survey> survey;
    std::vector<Video> videos;
    std::vector<GiftCount> giftsCount;
    std::optional<ThreadInfo> sharedThread;
    std::optional<int> threadId;
    std::optional<ThreadInfo> thread;
    std::optional<bool> highlighted;
    std::vector<MessageTag> messageTags;
    std::optional<bool> isFailToSend;
};

struct Bgm {
    int id;
    std::string musicUrl;
    std::optional<int> order;
    std::string title;
};

struct Activity {
    std::vector<User> birthdayUsers;
    std::optional<int> birthdayUsersCount;
    std::optional<int> createdAt;
    std::vector<User> followers;
    std::optional<int> followersCount;
    std::optional<Post> fromPost;
    std::vector<int> fromPostIds;
    std::optional<Group> group;
    int id;
    std::optional<Metadata> metadata;
    std::optional<Post> toPost;
    std::optional<std::string> type;
    std::optional<User> user;
    std::optional<int> vipReward;
};

struct Metadata
{
    std::optional<std::string> body;
    std::optional<bool> bulkInvitation;
    std::optional<std::string> contentPreview;
    std::optional<std::string> title;
    std::optional<std::string> url;
};

struct GifImageCategory {
    std::vector<GifImage> gifs;
    int id;
    std::optional<std::string> language;
    std::optional<std::string> name;
};

struct GifImage
{
    std::optional<std::string> height;
    int id;
    std::optional<std::string> ura;
    std::optional<int> width;
};

struct ChatRoom {
    std::optional<std::string> background;
    int id;
    std::optional<bool> isGroup;
    std::optional<bool> isRequest;
    std::optional<Message> lastMessage;
    std::vector<User> members;
    std::optional<std::string> name;
    std::optional<User> owner;
    std::optional<int> unreadCount;
    std::optional<int> updatedAt;
    std::optional<UserSetting> userSetting;
};

struct Message {
    std::optional<std::string> attachment;
    std::optional<std::string> attachmentAndroid;
    std::optional<int> attachmentReadCount;
    std::optional<std::string> attachmentThumbnail;
    std::optional<ConferenceCall> conferenceCall;
    std::optional<int> createdAt;
    std::optional<int> fontSize;
    std::optional<GifImage> gif;
    int id;
    std::optional<bool> isError;
    std::optional<bool> isSent;
    std::optional<std::string> messageType;
    std::optional<Message> parent;
    std::optional<int> refreshRetryCount;
    std::optional<int> roomId;
    std::optional<Sticker> sticker;
    std::optional<std::string> text;
    std::optional<int> userId;
    std::optional<bool> videoProcessed;
    std::optional<std::string> videoThumbnailUrl;
    std::optional<std::string> videoUrl;
};

struct UserSetting {
    std::optional<bool> notificationChat;
};

struct Sticker {
    std::optional<std::string> extension;
    std::optional<int> height;
    int id;
    std::optional<int> stickerPackId;
    std::optional<std::string> url;
    std::optional<int> width;
};

struct Settings {
    std::optional<bool> ageRestrictedOnReview;
    std::optional<bool> allowReposts;
    std::optional<bool> cautionUserChat;
    std::optional<bool> followingOnlyCallInvite;
    std::optional<bool> followingOnlyGroupInvite;
    std::optional<bool> followingRestrictedOnReview;
    std::optional<bool> hideActiveCall;
    std::optional<bool> hideHotPost;
    std::optional<bool> hideOnInvitable;
    std::optional<bool> hideOnlineStatus;
    std::optional<bool> hideReplyFollowingTimeline;
    std::optional<bool> hideReplyPublicTimeline;
    std::optional<bool> hideVip;
    std::optional<bool> invisibleOnUserSearch;
    std::optional<bool> noReplyGroupTimeline;
    std::optional<bool> notificationBirthdayToFollowers;
    std::optional<bool> notificationBulkCallInvite;
    std::optional<bool> notificationCallInvite;
    std::optional<bool> notificationChat;
    std::optional<bool> notificationChatDelete;
    std::optional<bool> notificationContactFriend;
    std::optional<bool> notificationDailySummary;
    std::optional<bool> notificationFollow;
    std::optional<bool> notificationFollowAccept;
    std::optional<bool> notificationFollowRequest;
    std::optional<bool> notificationFollowerConferenceCall;
    std::optional<bool> notificationFollowerCreateGroup;
    std::optional<bool> notificationFollowingBirthdateOn;
    std::optional<bool> notificationFollowingPostAfterBreak;
    std::optional<bool> notificationFollowingsInCall;
    std::optional<bool> notificationFootprint;
    std::optional<bool> notificationGroupAccept;
    std::optional<bool> notificationGroupConferenceCall;
    std::optional<bool> notificationGroupInvite;
    std::optional<bool> notificationGroupJoin;
    std::optional<bool> notificationGroupMessageTagAll;
    std::optional<bool> notificationGroupModerator;
    std::optional<bool> notificationGroupPost;
    std::optional<bool> notificationGroupRequest;
    std::optional<bool> notificationHimaNow;
    std::optional<bool> notificationLatestNews;
    std::optional<bool> notificationLike;
    std::optional<bool> notificationMessageTag;
    std::optional<bool> notificationPopularPost;
    std::optional<bool> notificationProfileScreenshot;
    std::optional<bool> notificationReply;
    std::optional<bool> notificationRepost;
    std::optional<bool> notificationReview;
    std::optional<bool> notificationSecurityWarning;
    std::optional<bool> notificationTwitterFriend;
    std::optional<bool> privacyMode;
    std::optional<bool> privatePost;
    std::optional<bool> privateUserTimeline;
    std::optional<bool> vipInvisibleFootprintMode;
    std::optional<bool> visibleOnSnsFriendRecommendation;
};

struct StickerPack {
    std::optional<std::string> cover;
    std::optional<std::string> description;
    int id;
    std::optional<std::string> name;
    std::optional<int> order;
    std::vector<Sticker> stickers;
};

struct Config {
    std::optional<std::string> adTesterUserIds;
    std::optional<std::string> isChatWebsocketEnabled;
    std::optional<std::string> isDirectVipPurchaseEnabled;
    std::optional<std::string> isGiftFeaturesEnabled;
    std::optional<std::string> isIdCardAndPhoneVerificationCheckForReviewEnabled;
    std::optional<std::string> isIdCardCheckRequiredBlockerViewEnabled;
    std::optional<std::string> isMaintenanced;
    std::optional<std::string> isPhoneVerificationRequiredBlockerViewEnabled;
    std::optional<std::string> isSpeedTestEnabled;
    std::optional<std::string> isStarEnabled;
    std::optional<std::string> latestAndroidAppVersion;
    std::optional<std::string> lineOfficialAccountId;
    std::optional<std::string> localizedMaintenanceUrl;
    std::optional<std::string> localizedNewsTitle;
    std::optional<std::string> localizedNewsUrl;
    std::optional<std::string> maintenanceFeatures;
    std::optional<std::string> maxImageFrameCount;
    std::optional<std::string> minimumAndroidAppVersionRequired;
    std::optional<std::string> minimumAndroidVersionSupported;
    std::optional<std::string> newsVersion;
    std::optional<std::string> promotionStickerPackIds;
    std::optional<std::string> shouldAppendUserIdToNewsUrl;
    std::optional<std::string> supportEmailAddress;
    std::optional<std::string> twitterOfficialAccountId;
    std::optional<std::string> useRandomMessageRefreshRate;
};

struct Application {
    std::optional<Config> settings;
};

struct BanWord {
    int id;
    std::optional<std::string> type;
    std::optional<std::string> word;
};

struct PopularWord {
    int id;
    std::string type;
    std::string word;
};

struct Walkthrough {
    std::string title;
    std::string url;
};

struct Gift {
    std::string icon;
    std::string iconThumbnail;
    int id;
    std::optional<int> price;
    std::string title;
};

struct GroupCategory {
    std::optional<std::string> icon;
    int id;
    std::optional<std::string> name;
    std::optional<int> rank;
    std::vector<int> gameIdSupportedCategoryIds; // タイプが不明なのでunknown型を使用
};

struct CreateGroupQuota {
    std::optional<int> remainingQuota;
    std::optional<int> usedQuota;
};

struct GroupSetting {
    std::optional<bool> notificationGroupJoin;
    std::optional<bool> notificationGroupMessageTagAll;
    std::optional<bool> notificationGroupPost;
    std::optional<bool> notificationGroupRequest;
};

struct PresignedUrl {
    std::string filename;
    std::string url;
};

struct Promotion {
    int id;
    std::string imageUrl;
    std::optional<int> order;
    std::string promotionUrl;
    std::string title;
};

struct MuteKeyword {
    std::vector<std::string> context;
    int id;
    std::string word;
};

struct PostTag {
    std::optional<int> id;
    std::optional<int> postHashtagsCount;
    std::optional<std::string> tag;
};

struct Review {
    std::string comment;
    std::optional<int> createdAt;
    int id;
    std::optional<bool> mutualReview;
    std::optional<int> reportedCount;
    std::optional<User> reviewer;
    std::optional<User> user;
};

struct TimelineSettings {
    std::optional<bool> favesFilter;
    std::optional<bool> hideHotPost;
    std::optional<bool> hideReplyFollowingTimeline;
    std::optional<bool> hideReplyPublicTimeline;
};

struct Footprint {
    int id;
    std::optional<User> user;
    std::optional<int> visitedAt;
};

struct UserWrapper {
    int id;
    std::optional<User> user;
};

struct RefreshCounterRequest {
    std::string counter;
    std::optional<int> lastRequestedAt;
    std::string status;
};

#endif