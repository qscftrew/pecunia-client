/**
 * Copyright (c) 2010, 2012, Pecunia Project. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#import <Cocoa/Cocoa.h>
#import "PecuniaSectionItem.h"

@class TransactionLimits;
@class StandingOrder;

@interface StandingOrderTabController : NSObject <PecuniaSectionItem> {
	IBOutlet NSTableView			*orderView;
	IBOutlet NSArrayController		*orderController;
	IBOutlet NSArrayController		*monthCyclesController;
	IBOutlet NSArrayController		*weekCyclesController;
	IBOutlet NSArrayController		*execDaysMonthController;
	IBOutlet NSArrayController		*execDaysWeekController;
	IBOutlet NSView					*mainView;
	IBOutlet NSButtonCell			*monthCell;
	IBOutlet NSButtonCell			*weekCell;
	IBOutlet NSPopUpButton			*monthCyclesPopup;
	IBOutlet NSPopUpButton			*weekCyclesPopup;
	IBOutlet NSPopUpButton			*execDaysMonthPopup;
	IBOutlet NSPopUpButton			*execDaysWeekPopup;
	IBOutlet NSSegmentedControl		*segmentView;
	IBOutlet NSWindow				*selectAccountPanel;
	IBOutlet NSWindow				*selectAccountWindow;
	IBOutlet NSArrayController		*accountsController;
	
	NSManagedObjectContext			*managedObjectContext;
	NSMutableArray					*accounts;
	NSArray							*weekDays;
	TransactionLimits				*currentLimits;
	StandingOrder					*currentOrder;
	NSNumber						*oldMonthCycle;
	NSNumber						*oldMonthDay;
	NSNumber						*oldWeekCycle;
	NSNumber						*oldWeekDay;
	
	NSNumber						*requestRunning;
}

@property (nonatomic, retain) NSNumber *requestRunning;
@property (nonatomic, retain) NSNumber *oldMonthCycle;
@property (nonatomic, retain) NSNumber *oldMonthDay;
@property (nonatomic, retain) NSNumber *oldWeekCycle;
@property (nonatomic, retain) NSNumber *oldWeekDay;
@property (nonatomic, retain) TransactionLimits *currentLimits;
@property (nonatomic, retain) StandingOrder *currentOrder;

-(NSView*)mainView;
-(void)initAccounts;
-(void)disableCycles;

-(IBAction)monthCycle:(id)sender;
-(IBAction)weekCycle:(id)sender;
-(IBAction)monthCycleChanged:(id)sender;
-(IBAction)monthDayChanged:(id)sender;
-(IBAction)weekCycleChanged:(id)sender;
-(IBAction)weekDayChanged:(id)sender;
-(IBAction)segButtonPressed:(id)sender;
-(IBAction)firstExecDateChanged:(id)sender;
-(IBAction)lastExecDateChanged:(id)sender;

-(IBAction)accountsOk:(id)sender;
-(IBAction)accountsCancel:(id)sender;
-(IBAction)update:(id)sender;
-(IBAction)getOrders:(id)sender;

// PecuniaSectionItem protocol.
@property (nonatomic, retain) Category* category;

- (NSView*)mainView;
- (void)initAccounts;
- (void)activate;
- (void)deactivate;
- (void)setTimeRangeFrom: (ShortDate*)from to: (ShortDate*)to;

@end



