#import <SenTestingKit/SenTestingKit.h>
#import <QSObject_ContactHandling.h>

@interface QSAddressBookPluginTests : SenTestCase

- (void)testImObjects;

- (void)createNewTestPersonWithMiddleName:(NSString *)middleName;
- (void)setupJabberAndSkype;
- (bool)usingNewInstantMessageAPI;

@end
