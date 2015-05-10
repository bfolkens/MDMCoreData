//
//  MDMMigrationManager.h
//
//  Created by Bradford Folkens on 5/8/15.
//

#import <Foundation/Foundation.h>

@class MDMMigrationManager;

@protocol MDMMigrationManagerDelegate <NSObject>

@optional
- (void)migrationManager:(MDMMigrationManager *)migrationManager migrationProgress:(float)migrationProgress;
- (NSArray *)migrationManager:(MDMMigrationManager *)migrationManager mappingModelsForSourceModel:(NSManagedObjectModel *)sourceModel;

@end

@interface MDMMigrationManager : NSObject

- (BOOL)progressivelyMigrateURL:(NSURL *)sourceStoreURL
                         ofType:(NSString *)type
                        toModel:(NSManagedObjectModel *)finalModel
                          error:(NSError **)error;

@property (nonatomic, weak) id<MDMMigrationManagerDelegate> delegate;

@end
