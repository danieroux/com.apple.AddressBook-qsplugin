/*
 *     Generated by class-dump (version 2.1.5).
 *
 *     class-dump is Copyright (C) 1997, 1999, 2000, 2001 by Steve Nygard.
 */

/*
 * File: /Applications/Address Book.app/Contents/Resources/Telephony.bundle/Contents/MacOS/Telephony
 */

#import <AddressBook/AddressBook.h>

@protocol ABPhoneStatusProtocol
- (void)statusChangedTo:(int)fp8;
@end

@interface ABConnectButton:NSView <ABPhoneStatusProtocol>
{
    ABPhoneConnection *_connection;
    int _status;
    NSMutableArray *_images;
    int _searchFrame;
    NSTimer *_statusAnimationTimer;
    NSMenu *_contextMenu;
    char _hit;
}

- findImageNamed:fp8;
- initWithFrame:(struct _NSRect)fp8;
- (void)dealloc;
- (void)setConnection:fp8;
- (void)statusChangedTo:(int)fp8;
- (void)advanceAnimation;
- (char)mouseDownCanMoveWindow;
- (void)mouseDown:fp8;
- (void)mouseDragged:fp8;
- (void)toggleState;
- (void)mouseUp:fp8;
- (void)keyDown:fp8;
- (char)acceptsFirstResponder;
- (char)becomeFirstResponder;
- (char)resignFirstResponder;
- (void)drawRect:(struct _NSRect)fp8;

@end

@interface ABConnectionWatcher:NSObject
{
    ABPhoneConnection *phoneConnection;
    NSMutableArray *_activePhonePanels;
}

- initWithPhoneConnection:fp8;
- (void)dealloc;
- (void)connectionTerminated;
- phoneConnection;
- findActivePhonePanelCreate:(char)fp8;
- (void)ringReceived;
- (void)removePhonePanel:fp8;
- (void)clipReceived:fp8;
- (void)parseCallerNumber:fp8;
- (void)elipReceived:fp8;
- (void)parseCallerIDName:fp8;
- (void)parseCallWaiting:fp8;
- (void)parseNewSMSList:fp8;
- (void)fetchNextBitsForSMSMessage:fp8;
- (void)displayInboundSMSMessage:fp8;
- (void)okResults:fp8 forCommand:fp12;
- (void)receivedERROR;

@end

@interface ABOBEXController:NSObject
{
    NSProgressIndicator *indicator;
    NSWindow *window;
    NSTextField *labelField;
    NSButton *doneButton;
    NSWindow *_mainWindow;
    NSArray *_people;
    IOBluetoothOBEXSession *_OBEXSession;
    IOBluetoothDevice *_OBEXDevice;
    IOBluetoothSDPServiceRecord *_serviceRecord;
    char _reconnectToPhone;
    char _abortIsDesired;
    char _transferInProgress;
    char _done;
    NSData *_tempPutDataBuffer;
    unsigned int _currentDataSize;
    unsigned int _dataSentSoFar;
    int _error;
    struct __CFData *_putHeadersDataRef;
    NSData *_currentData;
    unsigned short _maxPacketLength;
    NSTimer *_abortTimer;
    NSTimer *_waitingForPhoneTimer;
    unsigned int _lastFileOffset;
}

- init;
- (void)cleanupWaitingTimer;
- (void)dealloc;
- (void)setLabelString:fp8;
- (void)presentWaitingForPhone;
- (void)putUpSheet;
- (void)sheetDidEnd:fp8 returnCode:(int)fp12 contextInfo:(void *)fp16;
- (void)tearDownSheet;
- vCardData;
- (void)cancelTransfer:fp8;
- (void)abortTimerFired:fp8;
- (char)isASyncedDevice:(struct OpaqueIOBluetoothObjectRef *)fp8;
- (void)createAdHocOBEXConnection;
- (void)finishCreatingAdHocOBEXConnection;
- (void)transportConnectionCallback:(void *)fp8 status:(int)fp12;
- (void)SessionResponseCallback:(struct OBEXSessionEvent *)fp8;
- (void)OBEXConnectHandler:(struct OBEXConnectCommandResponseData *)fp8;
- (void)OBEXPutHandler:(struct OBEXPutCommandResponseData *)fp8;
- (void)OBEXAbortHandler:(struct OBEXAbortCommandResponseData *)fp8;
- (void)OBEXDisconnectHandler:(struct OBEXDisconnectCommandResponseData *)fp8;
- (void)completeTransfer:fp8;
- (void)startFilePut;
- getNextFileChunkOptionalHeaderLength:(unsigned long)fp8 isLastChunk:(STR)fp12;
- (void)updateUI:(int)fp8 errorCode:(int)fp12 bytesSent:(int)fp16 bytesTotal:(int)fp20;
- (void)closeCurrentConnection;
- (void)reopenCurrentConnection;
- (void)sendPeople:fp8 fromWindow:fp12;

@end

@interface ABPhoneConnection:NSObject
{
    char sendBuffer[1000];
    int offset;
    NSMutableArray *commandArray;
    NSMutableArray *unsolicitCodeHandlers;
    ABConnectionWatcher *connectionWatcher;
    NSData *smsMessageData;
    SEL nextLineSelector;
    id nextLineOwner;
    id _statusDelegate;
    ABSendSMSController *SMSSendController;
    ABReceiveSMSController *SMSReceiveController;
    int connectionStatus;
    IOBluetoothSDPServiceRecord *_serviceRecord;
    IOBluetoothRFCOMMChannel *_RFCOMMChannel;
    struct OpaqueIOBluetoothDeviceSearchRef *_searchRef;
    NSMutableDictionary *_deviceCommandSet;
    NSMutableArray *_allCommandSets;
}

- (void)commonInit;
- initWithServiceRecord:fp8;
- initWithCoder:fp8;
- (void)encodeWithCoder:fp8;
- (void)dealloc;
- (void)applicationWillTerminate:fp8;
- (void)_setupOpenConnection;
- (void)connectionComplete:fp8 status:(int)fp12;
- (void)openConnection;
- (void)connectionTerminated;
- (void)closeConnection;
- (void)setConnectionStatus:(int)fp8;
- (int)connectionStatus;
- (void)setStatusDelegate:fp8;
- statusDelegate;
- (void)handleRead:(void *)fp8 ofSize:(unsigned short)fp12;
- (void)setSMSMessageData:fp8;
- deviceCommandForKey:fp8;
- (void)writePhoneString:fp8;
- (void)writePhoneString:fp8 withSelector:(SEL)fp12 withOwner:fp16;
- (void)setNextLineOwner:fp8 andSelector:(SEL)fp12;
- (void)sendCommandData:fp8;
- (void)sendCommand:fp8;
- (void)okResults:fp8 forCommand:fp12;
- (char)ATIResult:fp8 matchesDeviceFamily:fp12;
- (void)checkForATIResults:fp8;
- (void)registerSelector:(SEL)fp8 withOwner:fp12 forUnsolicitedCode:fp16;
- (void)ringReceived;
- (void)parseResponse:(STR)fp8 withLength:(int)fp12;
- (void)processQueuedCommands;
- (void)receivedERROR;
- (void)handleErrorResponse;
- (void)okToSend:fp8;
- phoneName;
- (void)setServiceRecord:fp8;
- serviceRecord;
- (char)canSendSMS;
- (char)canDial;

@end

@interface ABPhonePanelController:NSObject
{
    NSButton *releaseButton;
    NSButton *answerButton;
    NSButton *releaseAndAnswerButton;
    NSButton *SMSButton;
    NSButton *saveButton;
    NSTextField *phoneNameField;
    NSTextField *phoneNumberField;
    NSImageView *phoneIcon;
    NSTextField *ringCountLabel;
    NSWindow *window;
    ABConnectionWatcher *connectionWatcher;
    NSString *callerNumber;
    NSString *callerName;
    ABPerson *callerRecord;
    NSString *callerIdentifier;
    NSTimer *timer;
    NSTimer *cancelRingsTimer;
    char wantsRings;
    int ringCount;
    char hasACallWaiting;
    char hasLineData;
}

- initWithConnectionWatcher:fp8;
- (void)dealloc;
- (void)awakeFromNib;
- (char)wantsRings;
- (void)setCallerName:fp8;
- (void)setCallerNumber:fp8;
- (void)setHasACallWaiting:(char)fp8;
- (char)hasLineData;
- (void)setCLIP:fp8;
- (void)setCallWaiting:fp8;
- (void)setCallerRecord:fp8 identifier:fp12;
- callerRecord;
- (void)cancelRingRequestAfterDelay:(int)fp8;
- (void)cancelRingRequest;
- (void)decline;
- (void)accept;
- (void)connectionTerminated;
- _model;
- (void)handleSaveButton:fp8;
- (void)handleReleaseAndAnswer:fp8;
- (void)handleAcceptButton:fp8;
- (void)handleDeclineButton:fp8;
- (void)handleSMSButton:fp8;
- (void)sheetDidEnd:fp8 returnCode:(int)fp12 contextInfo:fp16;
- (void)presentUnknownLabel;
- (void)ringReceived;
- autorelease;
- (oneway void)release;
- (void)closeIncomingCallPanel;
- (void)handleTimer:fp8;
- (void)okResults:fp8 forCommand:fp12;
- (void)receivedERROR;

@end

@interface ABReceiveSMSController:NSObject
{
    ABConnectionWatcher *connectionWatcher;
    NSData *vCard;
    ABSMSMessage *message;
    ABPerson *callerRecord;
    NSString *callerIdentifier;
    NSButton *saveButton;
    NSTextField *phoneName;
    NSTextField *phoneNumber;
    NSTextView *smsText;
    NSWindow *window;
    id personIcon;
}

- initWithConnectionWatcher:fp8;
- (void)dealloc;
- (void)awakeFromNib;
- (void)setMessage:fp8;
- (void)setCallerRecord:fp8 identifier:fp12;
- (void)handleSave:fp8;
- (void)handleOK:fp8;
- (void)handleCancel:fp8;
- (void)handleReply:fp8;
- (void)sheetDidEnd:fp8 returnCode:(int)fp12 contextInfo:fp16;

@end

@interface ABSendSMSController:NSObject
{
    NSTextView *message;
    NSTextField *messageCount;
    NSTextField *messageToNumber;
    NSTextField *messageToName;
    NSButton *sendButton;
    NSPanel *window;
    NSString *displayedPhoneNumber;
    NSString *phoneNumber;
    NSString *phoneName;
    ABPhoneConnection *phoneConnection;
}

- initWithPhoneNumber:fp8 name:fp12 andConnection:fp16;
- initWithPerson:fp8 identifier:fp12 andConnection:fp16;
- (void)dealloc;
- window;
- (void)awakeFromNib;
- (void)cancel:fp8;
- (char)containsUnicodeChars:fp8;
- (void)sendMessage:fp8;
- (void)updateMessageCount:fp8;
- (char)textView:fp8 shouldChangeTextInRange:(struct _NSRange)fp12 replacementString:fp20;
- (void)textDidChange:fp8;

@end

@interface ABSMSMessage:NSObject
{
    int SCALength;
    NSString *SCA;
    NSString *SMSDeliver;
    int addressLength;
    NSString *typeOfAddress;
    NSString *senderNumber;
    NSString *protocolID;
    NSString *dataCodingScheme;
    NSString *timeStamp;
    int userDataLength;
    NSString *userData;
    NSString *unencodedMessage;
    NSString *unencodedPhoneNumber;
    char useGSMPhoneScheme;
}

- initWithPDUString:fp8;
- initWithMessage:fp8 andPhoneNumber:fp12;
- (void)dealloc;
- message;
- containedVCard;
- phoneNumber;
- description;
- pduData;

@end

@interface ABTelephonyController:NSObject
{
    ABPhoneConnection *_primaryConnection;
    ABConnectButton *_connectButton;
    NSView *_contentView;
}

+ (void)load;
+ sharedTelephonyController;
+ mainWindowController;
- init;
- (void)finishSetup;
- (void)dealloc;
- (void)startConnectingToPrimaryPhone;
- inputController;
- (void)setupAddressBookUI;
- (char)validateMenuItem:fp8;
- (void)dialPhone:fp8;
- (void)SMSMessagePhone:fp8;
- (void)sheetDidEnd:fp8 returnCode:(int)fp12 contextInfo:fp16;
- peopleInRecords:fp8;
- (void)sendThisCard:fp8;
- (char)isConnectionPaired:fp8;
- primaryConnection;
- (void)removePrimaryConnection;
- discoverNewPrimaryConnection;
- (void)selectPhone;
- titleForRollOverIdentifier:fp8 withSelection:fp12;
- propertyForRollOverIdentifier:fp8;
- (char)shouldEnableRollOverIdentifier:fp8 withSelection:fp12;
- (void)chooseRollOverIdentifier:fp8 withSelection:fp12;

@end

