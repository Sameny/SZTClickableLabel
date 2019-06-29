//
//  SZTClickableLabel.h
//  PlayerWithDub
//
//  Created by 舒泽泰 on 2018/11/21.
//  Copyright © 2018 泽泰 舒. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SZTClickableLabel;
@protocol SZTClickableLabelDelegate <NSObject>

@optional
- (void)clickableLabel:(SZTClickableLabel *)label didClickedAtWord:(NSString *)word;

@end

BOOL canTouchWithText(NSString *text);

@interface SZTClickableLabel : UIView

@property (nonatomic, copy) NSArray <NSString *>*titles; // you can set 'titles' to show Chinese or English.When setted, The title property will be nil.
@property (nonatomic, copy) NSArray <NSDictionary <NSAttributedStringKey, id>*>*normalAttributesForIndex; // You can set this property to show diffirent color or font.. for diffirent index. if setted, normalAttributes will be invalid for the same attribute. if nil, normalAttributes will be used.

@property (nonatomic, copy) NSString *title; // Now jush can show English
@property (nonatomic, strong, readonly) NSString *clickedText;

@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *textColor;

@property (nonatomic, assign) CGFloat wordSpacing;
@property (nonatomic, assign) CGFloat lineSpacing;

@property (nonatomic, assign) CGFloat normalCornerRarius;
@property (nonatomic, assign) CGFloat clickedCornerRarius;

@property (nonatomic, readonly) CGSize contentSize;

@property (nonatomic, copy) NSDictionary <NSAttributedStringKey, id>*normalAttributes; // 该属性是针对所有title
@property (nonatomic, copy) NSDictionary <NSAttributedStringKey, id>*clickedAttributes;

@property (nonatomic, assign) BOOL clickable; // default is YES
@property (nonatomic, weak) id<SZTClickableLabelDelegate> delegate;


- (instancetype)initWithFrame:(CGRect)frame textBackgroundInsets:(UIEdgeInsets)insets NS_DESIGNATED_INITIALIZER;

- (CGSize)adjustContentSizeWithTitles:(NSArray <NSString *>*)titles;
- (void)szt_sizeToFit;
- (void)cancelClickedState;

@end

NS_ASSUME_NONNULL_END
