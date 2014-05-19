//
//  QMChatService.h
//  Q-municate
//
//  Created by Igor Alefirenko on 17/02/2014.
//  Copyright (c) 2014 Quickblox. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface QMChatService : NSObject


@property (strong, nonatomic) NSMutableDictionary *allConversations;
@property (strong, nonatomic) NSMutableArray *allDialogs;

@property (strong, nonatomic) QBWebRTCVideoChat *activeStream;

@property (strong, nonatomic) NSString *currentSessionID;
@property (nonatomic, strong) NSDictionary *customParams;

+ (instancetype)shared;

// Log In & Log Out
- (void)loginWithUser:(QBUUser *)user completion:(QBChatResultBlock)block;
- (void)logOut;


#pragma mark - Chat

- (void)sendMessage:(QBChatMessage *)message;
- (void)createRoomWithName:(NSString *)groupChatNameString withCompletion:(QBChatRoomResultBlock)block;
- (void)addMembersArray:(NSArray *)membersArray toRoom:(QBChatRoom *)chatRoom;


#pragma mark - Audio/Video Calls

- (void)initActiveStream;                                                                           // for audio calls
- (void)initActiveStreamWithOpponentView:(UIView *)opponentView ownView:(UIView *)ownView;          // for video calls
- (void)releaseActiveStream;

- (void)callUser:(NSUInteger)userID withVideo:(BOOL)videoEnabled;

- (void)acceptCallFromUser:(NSUInteger)userID withVideo:(BOOL)videoEnabled customParams:(NSDictionary *)customParameters;
- (void)rejectCallFromUser:(NSUInteger)userID;

- (void)cancelCall;
- (void)finishCall;

@end
