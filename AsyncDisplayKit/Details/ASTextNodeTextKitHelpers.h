/* Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <objc/message.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ASTextKitComponents : NSObject

@property (nonatomic, strong, readonly) NSTextStorage *textStorage;
@property (nonatomic, strong, readonly) NSTextContainer *textContainer;
@property (nonatomic, strong, readonly) NSLayoutManager *layoutManager;

- (instancetype)initWithTextStorage:(NSTextStorage *)textStorage
                      textContainer:(NSTextContainer *)textContainer
                      layoutManager:(NSLayoutManager *)layoutManager;

@end

// Convenience.
/**
  @abstract Creates the stack of TextKit components.
  @param attributedSeedString The attributed string to sed the returned text storage with, or nil to receive an blank text storage.
  @param textContainerSize The size of the text-container. Typically, size specifies the constraining width of the layout, and FLT_MAX for height. Pass CGSizeZero if these components will be hooked up to a UITextView, which will manage the text container's size itself.
  @return A `ASTextKitComponents` containing the created components. The text view component will be nil.
  @discussion The returned components will be hooked up together, so they are ready for use as a system upon return.
 */
extern ASTextKitComponents *ASTextKitComponentsCreate(NSAttributedString *attributedSeedString, CGSize textContainerSize);
