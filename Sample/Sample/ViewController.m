//
//  ViewController.m
//  Sample
//
//  Created by 泽泰 舒 on 2019/6/29.
//  Copyright © 2019年 泽泰 舒. All rights reserved.
//

#import "SZTClickableLabel.h"
#import "ViewController.h"

@interface ViewController () <SZTClickableLabelDelegate>
@property (nonatomic, strong) SZTClickableLabel *clickableLabel;

@property (nonatomic, strong) UILabel *selectedLabel;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.clickableLabel = [[SZTClickableLabel alloc] initWithFrame:CGRectMake(30, 100, 200, 300)];
//    self.clickableLabel.title = @"i am a boy!";
    self.clickableLabel.titles = @[@"sssssssssaaaaaaaa", @"ss", @"ssff", @"tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt"]; // 超出将只显示为一行
    self.clickableLabel.delegate = self;
    self.clickableLabel.clickedAttributes = @{NSBackgroundColorAttributeName:[UIColor redColor]};
    self.clickableLabel.normalAttributes = @{NSForegroundColorAttributeName:[UIColor purpleColor]};
    [self.view addSubview:self.clickableLabel];
    
    self.selectedLabel = [[UILabel alloc] initWithFrame:CGRectMake(80, 420, 100, 30)];
    [self.view addSubview:self.selectedLabel];
    self.selectedLabel.text = @"请点击";
}

#pragma mark - SZTClickableLabelDelegate
- (void)clickableLabel:(SZTClickableLabel *)label didClickedAtWord:(NSString *)word {
    self.selectedLabel.text = word;
    self.selectedLabel.frame = CGRectMake(80, CGRectGetMaxY(label.frame) + 20, 100, 30);
}

@end
