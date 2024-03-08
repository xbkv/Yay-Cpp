#ifndef RESPONSE_H
#define RESPONSE_H

#include <YayCpp/Utils/Models.hpp>

struct BlockedUserIdsResponse
{
    std::vector<int> blockIds;
};

struct BlockUsersResponce
{
    int blockedCount;
    int lastId;
    std::vector<int> users;
};

struct PostResponce
{
    Post post;
};

struct PostsResponse {
    std::optional<bool> hasMoreHotPosts;
    std::optional<std::string> nextPageValue;
    std::vector<Post> pinnedPosts;
    std::vector<Post> posts;
};

struct BgmsResponse {
    std::vector<Bgm> bgm;
};

struct ConferenceCallResponse {
    std::optional<ConferenceCall> conferenceCall;
    std::optional<std::string> conferenceCallUserUuid;
};

struct UsersByTimestampResponse {
    std::optional<int64_t> lastTimestamp;
    std::vector<User> users;
};

struct CallStatusResponse {
    std::optional<bool> phoneStatus;
    std::optional<std::string> roomUrl;
    std::optional<bool> videoStatus;
};

struct GamesResponse {
    std::optional<int> fromId;
    std::vector<Game> games;
};

struct GenresResponse {
    std::vector<Genre> genres;
    std::optional<std::string> nextPageValue;
};

struct UserTimestampResponse {
    int64_t time;
    std::string ipAddress;
    std::string country;
};

struct SnsInfo {
    std::string type;
    std::string uid;
    std::string nickname;
    std::string biography;
    std::string profileImage;
    std::string gender;
};

struct LoginUserResponse {
    int userId;
    std::optional<std::string> username;
    std::optional<bool> isNew;
    std::optional<SnsInfo> snsInfo;
    std::string accessToken;
    std::string refreshToken;
    std::optional<std::string> tokenType;
    std::optional<int64_t> createdAt;
    std::optional<int64_t> expiresIn;
};

struct ActivitiesResponse {
    std::vector<Activity> activities;
    std::optional<int64_t> lastTimestamp;
};

struct UnreadStatusResponse {
    std::optional<bool> isUnread;
};

struct CreateChatRoomResponse {
    int roomId;
};

struct FollowUsersResponse {
    std::optional<int> lastFollowId;
    std::vector<User> users;
};

struct GifsDataResponse {
    std::vector<GifImageCategory> gifCategories;
};

struct ChatRoomResponse {
    std::optional<ChatRoom> chat;
};

struct ChatRoomsResponse {
    std::vector<ChatRoom> chatRooms;
    std::optional<std::string> nextPageValue;
    std::optional<std::vector<ChatRoom>> pinnedChats;
};


struct MessagesResponse {
    std::vector<Message> messages;
};

struct AdditionalSettingsResponse {
    std::optional<Settings> setting;
};

struct NotificationSettingResponse {
    UserSetting setting;
};

struct StickerPacksResponse {
    std::vector<StickerPack> stickerPacks;
};

struct TotalChatRequestResponse {
    std::optional<int> total;
};

struct ApplicationConfigResponse {
    std::optional<Application> app;
};

struct BanWordsResponse {
    std::vector<BanWord> banWords;
};

struct PopularWordsResponse {
    std::vector<PopularWord> popularWords;
};

struct GiftingAbilitiesResponse {
    std::vector<GiftingAbility> giftingAbilities;
};

struct GiftsResponse {
    std::vector<Gift> gifts;
    std::optional<std::string> nextPageValue;
    std::optional<int> totalCount;
};

struct GiftSendersResponse {
    std::vector<User> senders;
    std::optional<int> totalSendersCount;
};

struct CreateGroupResponse {
    std::optional<int> groupId;
};

struct UserResponse {
    std::optional<std::string> birthDate;
    std::optional<int> blockingLimit;
    std::optional<bool> emailConfirmed;
    std::optional<bool> facebookConnected;
    std::optional<GiftingAbility> giftingAbility;
    std::optional<bool> groupPhoneOn;
    std::optional<bool> groupVideoOn;
    std::optional<int> interestsCount;
    std::optional<bool> lineConnected;
    std::optional<bool> lobiConnected;
    std::optional<std::string> maskedEmail;
    std::optional<bool> phoneOn;
    std::optional<bool> pushNotification;
    std::optional<std::string> twitterId;
    std::optional<User> user;
    std::optional<std::string> uuid;
    std::optional<bool> videoOn;
    std::optional<int> vipUntil;
};

struct UsersResponse {
    std::optional<std::string> nextPageValue;
    std::vector<User> users;
};

struct GroupCategoriesResponse {
    std::vector<GroupCategory> groupCategories;
};

struct CreateQuotaResponse {
    CreateGroupQuota create;
};

struct GroupResponse {
    std::optional<Group> group;
};

struct GroupNotificationSettingsResponse {
    std::optional<GroupSetting> setting;
};

struct GroupsResponse {
    std::optional<std::vector<Group>> groups;
    std::optional<std::vector<Group>> pinnedGroups;
};

struct GroupUserResponse {
    GroupUser groupUser;
};

struct GroupUsersResponse {
    std::vector<GroupUser> groupUsers;
};

struct GroupsRelatedResponse {
    std::vector<Group> groups;
    std::optional<std::string> nextPageValue;
};

struct HiddenResponse {
    std::vector<User> hiddenUsers;
    std::optional<int> limit;
    std::optional<std::string> nextPageValue;
    std::optional<int> totalCount;
};

struct LoginUpdateResponse {
    std::string accessToken;
    std::optional<int> expiresIn;
    std::string refreshToken;
    std::optional<int> userId;
    std::optional<std::string> username;
};

struct TokenResponse {
    std::string accessToken;
    std::optional<int> createdAt;
    std::optional<int> expiresIn;
    std::optional<int> id;
    std::string refreshToken;
};

struct RegisterDeviceTokenResponse {
    std::optional<int> createdAt;
    std::optional<int> id;
    std::optional<std::string> serverDeviceId;
    std::optional<int> updatedAt;
    std::optional<std::string> uuid;
};

struct EmailGrantTokenResponse {
    std::string emailGrantToken;
};

struct EmailVerificationPresignedUrlResponse {
    std::string url;
};

struct PresignedUrlsResponse {
    std::vector<PresignedUrl> presignedUrls;
};

struct IdCheckerPresignedUrlResponse {
    std::string presignedUrl;
};

struct PresignedUrlResponse {
    std::string presignedUrl;
};

struct PolicyAgreementsResponse {
    std::optional<bool> latestPrivacyPolicyAgreed;
    std::optional<bool> latestTermsOfUseAgreed;
};

struct PromotionsResponse {
    std::vector<Promotion> promotions;
};

struct VipGameRewardUrlResponse {
    std::string url;
};

struct WebSocketTokenResponse {
    std::string token;
};

struct VerifyDeviceResponse {
    std::optional<bool> verified;
    std::string verifiedAt;
};

struct CreateMuteKeywordResponse {
    MuteKeyword hiddenWord;
};

struct MuteKeywordResponse {
    std::vector<MuteKeyword> hiddenWords;
};

struct BookmarkPostResponse {
    std::optional<bool> bookmarked;
};

struct CreatePostResponse {
    std::optional<ConferenceCall> conferenceCall;
    std::optional<Post> post;
};

struct PostLikersResponse {
    std::optional<int> lastId;
    std::vector<User> users;
};

struct PostTagsResponse {
    PostTag tags;
};

struct LikePostsResponse {
    std::vector<int> likeIds;
};

struct ValidationPostResponse {
    std::optional<bool> result;
};

struct VoteSurveyResponse {
    std::optional<Survey> survey;
};

struct ReviewsResponse {
    std::vector<Review> pinnedReviews;
    std::vector<Review> reviews;
};

struct GroupThreadListResponse {
    std::optional<std::string> nextPageValue;
    std::vector<ThreadInfo> threads;
};

struct CreateUserResponse {
    std::string accessToken;
    std::optional<int> expiresIn;
    int id;
    std::string refreshToken;
};

struct ActiveFollowingsResponse {
    std::optional<int> lastLoggedinAt;
    std::vector<User> users;
};

struct DefaultSettingsResponse {
    std::optional<TimelineSettings> timelineSettings;
};

struct FollowRecommendationsResponse {
    std::optional<int> next;
    std::optional<int> total;
    std::vector<User> users;
};

struct FollowRequestCountResponse {
    std::optional<int> usersCount;
};

struct FootprintsResponse {
    std::vector<Footprint> footprints;
};

struct HimaUsersResponse {
    std::vector<UserWrapper> himaUsers;
};

struct RefreshCounterRequestsResponse {
    RefreshCounterRequest resetCounterRequests;
};

struct UserCustomDefinitionsResponse {
    std::optional<int> age;
    std::optional<int> createdAt;
    std::optional<int> followersCount;
    std::optional<int> followingsCount;
    std::optional<int> lastLoggedinAt;
    std::optional<int> reportedCount;
    std::optional<std::string> status;
};

struct UserEmailResponse {
    std::optional<std::string> email;
};

#endif