//
//  ViewController.m
//  TouchID
//
//  Created by jieku on 2017/6/13.
//  Copyright © 2017年 jieku. All rights reserved.
//

#import "ViewController.h"
#import "BasicTouchID.h"

@interface ViewController ()<BasicTouchIDDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    [BasicTouchID startWJTouchIDWithMessage:@"确定" fallbackTitle:@"取消" delegate:self];
}

- (void)TouchIDAuthorizeCallBackState:(TouchID_AuthorizeState)TouchID_AuthorizeState{
    
    switch (TouchID_AuthorizeState) {
        case TouchID_AuthorizeState_Success:
        {
            NSLog(@"TouchID 验证成功");
        }
            break;
            case TouchID_AuthorizeState_Failure:
        {
            NSLog(@"TouchID 验证失败");
        }
            break;
            case TouchID_AuthorizeState_ErrorUserCancel:
        {
            NSLog(@"点击了输入密码");
        }
            break;
            
        default:
        {
            NSLog(@"设备不支持TouchID");
        }
            break;
    }
}


@end
