#import "QSAddressBookPluginTests.h"

@implementation QSAddressBookPluginTests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

- (void)testExample
{
        ABPerson *person = [[ABAddressBook sharedAddressBook] me];
        STAssertNotNil(person, @"Expected %@ to be initialized from the shared address book", person);
        
        NSArray *imObjects = [QSContactObjectHandler imObjectsForPerson: person asChild:NO];
        
        STAssertNotNil(imObjects, @"Expected a result set of IM objects");
}

@end
