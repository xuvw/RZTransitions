//
//  RZTransitionInteractionControllerProtocol.h
//  RZTransitions
//
//  Created by Stephen Barnes on 12/4/13.
//  Copyright (c) 2013 Raizlabs. All rights reserved.
//

#ifndef RZTransitions_RZTransitionInteractorProtocol_h
#define RZTransitions_RZTransitionInteractorProtocol_h

typedef NS_ENUM (NSInteger, RZTransitionAction) {
    RZTransitionAction_Push     = (1 << 0),
    RZTransitionAction_Pop      = (1 << 1),
    RZTransitionAction_Present  = (1 << 2),
    RZTransitionAction_Dismiss  = (1 << 3),
};

@protocol RZTransitionInteractionController;
@protocol RZTransitionInteractionControllerDelegate;

@protocol RZTransitionInteractionControllerDelegate <NSObject>

@optional
- (UIViewController *)nextViewControllerForInteractor:(id<RZTransitionInteractionController>)interactor;

@end

@protocol RZTransitionInteractionController <UIViewControllerInteractiveTransitioning>

@required

@property (nonatomic, assign, readwrite) BOOL isInteractive;
@property (nonatomic, assign, readwrite) BOOL shouldCompleteTransition;
@property (nonatomic, assign, readwrite) RZTransitionAction action;
@property (nonatomic, weak) id<RZTransitionInteractionControllerDelegate> delegate;

- (void)attachViewController:(UIViewController *)viewController withAction:(RZTransitionAction)action;

@end

#endif
