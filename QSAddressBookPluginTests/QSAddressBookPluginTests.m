#import "QSAddressBookPluginTests.h"

@implementation QSAddressBookPluginTests

ABPerson *person;

- (void)setUp
{
    [super setUp];
    
    NSString *testString = @"QSTestUser";
    
    ABSearchElement *find = [ABPerson searchElementForProperty: kABMiddleNameProperty
                                                         label: nil
                                                           key: nil
                                                         value: testString
                                                    comparison: kABEqual];
    
    ABAddressBook *ab = [ABAddressBook addressBook];
    
    NSArray *results = [ab recordsMatchingSearchElement: find];
    
    if ([results count] == 0) {
        [self createNewTestPersonWithMiddleName: testString];
        
        results = [ab recordsMatchingSearchElement: find];
        
        NSLog(@"Added a new test user in the address book with the middle name %@", testString);
    }
    
    STAssertTrue(1 == [results count], @"Expected to find only one result for %@", testString);
    person = [results objectAtIndex: 0];    
}

- (void)testImObjects
{
    STAssertNotNil(person, @"Expected person to be initialized in setup");
    
    [self setupJabberAndSkype];
    
    NSArray *imObjects = [QSContactObjectHandler imObjectsForPerson: person asChild:NO];
    STAssertNotNil(imObjects, @"Expected a result set of IM objects");
    
    STAssertTrue(2 == [imObjects count], nil);
    
    QSBasicObject *qsObject = [imObjects objectAtIndex: 0];
    STAssertEqualObjects(@"Quick Silver's home Jabber", [qsObject displayName], @"Got %@", [qsObject displayName]);
    STAssertEqualObjects(@"qs.im.account", [qsObject kind], @"Got %@", [qsObject kind]);
    
    qsObject = [imObjects objectAtIndex: 1];
    STAssertEqualObjects(@"Quick Silver's work Skype", [qsObject displayName], @"Got %@", [qsObject displayName]);
    STAssertEqualObjects(@"qs.im.account", [qsObject kind], @"Got %@", [qsObject kind]);
}

- (void)createNewTestPersonWithMiddleName:(NSString *)middleName
{
    ABPerson *newPerson = [[ABPerson alloc] init];
    
    [newPerson setValue: @"Quick" forProperty: kABFirstNameProperty];
    [newPerson setValue: middleName forProperty: kABMiddleNameProperty];
    [newPerson setValue: @"Silver" forProperty: kABLastNameProperty];
    
    ABAddressBook *ab = [ABAddressBook addressBook];
    [ab addRecord: newPerson];     
    [ab save];
    
    [newPerson release];  
}

- (void)setupJabberAndSkype {
    ABMutableMultiValue *imList = [[ABMutableMultiValue alloc] init];
    
    NSDictionary *jabber = [NSDictionary dictionaryWithObjectsAndKeys: @"qs@example.com", kABInstantMessageUsernameKey,
                            kABInstantMessageServiceJabber, kABInstantMessageServiceKey,
                            nil]; 
    
    NSDictionary *skype = [NSDictionary dictionaryWithObjectsAndKeys: @"quicksilver.skype.example", kABInstantMessageUsernameKey,
                           kABInstantMessageServiceSkype, kABInstantMessageServiceKey,
                           nil];
    
    [imList addValue: jabber withLabel: kABHomeLabel];
    [imList addValue: skype withLabel: kABWorkLabel];
    
    STAssertTrue([person setValue: imList forProperty: kABInstantMessageProperty], nil);
    STAssertTrue([[ABAddressBook addressBook] save], @"Expected address book to save");
}

@end
