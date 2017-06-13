//
//  BasicTouchID.h
//  TouchID
//
//  Created by jieku on 2017/6/13.
//  Copyright © 2017年 jieku. All rights reserved.
//


#import <LocalAuthentication/LocalAuthentication.h>

typedef NS_ENUM(NSUInteger, TouchID_AuthorizeState) {
    /**
     *  TouchID验证成功
     *
     */
    TouchID_AuthorizeState_Success = 1,
    /**
     *  TouchID验证失败
     *
     */
    TouchID_AuthorizeState_Failure,//2
    /**
     *  取消TouchID验证 (用户点击了取消)
     *
     */
    TouchID_AuthorizeState_ErrorUserCancel,//3
    /**
     *  在TouchID对话框中点击输入密码按钮
     *
     */
    TouchID_AuthorizeState_ErrorUserFallback,//4
    /**
     *  在验证的TouchID的过程中被系统取消 例如突然来电话、按了Home键、锁屏...
     *
     */
    TouchID_AuthorizeState_ErrorSystemCancel,//5
    /**
     *  无法启用TouchID,设备没有设置密码
     *
     */
    TouchID_AuthorizeState_ErrorPasscodeNotSet,//6
    /**
     *  设备没有录入TouchID,无法启用TouchID
     *
     */
    TouchID_AuthorizeState_ErrorTouchIDNotEnrolled,//7
    /**
     *  该设备的TouchID无效
     *
     */
    TouchID_AuthorizeState_ErrorTouchIDNotAvailable,//8
    /**
     *  多次连续使用Touch ID失败，Touch ID被锁，需要用户输入密码解锁
     *
     *
     */
    TouchID_AuthorizeState_ErrorTouchIDLockout,//9
    /**
     *  当前软件被挂起取消了授权(如突然来了电话,应用进入前台)
     *
     */
    TouchID_AuthorizeState_ErrorAppCancel,//10
    /**
     *  当前软件被挂起取消了授权 (授权过程中,LAContext对象被释)
     *
     */
    TouchID_AuthorizeState_ErrorInvalidContext,//11
    /**
     *  当前设备不支持指纹识别
     *
     */
    TouchID_AuthorizeState_ErrorNotSupport,//12
};

@protocol BasicTouchIDDelegate <NSObject>

@required

- (void)TouchIDAuthorizeCallBackState:(TouchID_AuthorizeState)TouchID_AuthorizeState;
@end

@interface BasicTouchID : LAContext

@property (nonatomic, weak) id<BasicTouchIDDelegate> delegate;

/**
 *  发起TouchID验证 
 *
 *  @param message 提示框需要显示的信息 默认为：输入密码 (Fallback button title. Default is "Enter Password")
 */
+ (void)startWJTouchIDWithMessage:(NSString *)message fallbackTitle:(NSString *)fallbackTitle delegate:(id<BasicTouchIDDelegate>)delegate;

@end
