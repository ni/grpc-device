/*
    **** THIS FILE IS GENERATED. ANY CHANGES WILL BE OVERWRITTEN! ****
    Command-line: /P/MI/shared/hapigen/hapigen/export/1.2/1.2.0f0/tools/linux/i386/hapigen_render --processed-metadata-path /P/MI/shared/hapigen/hapigen_cheader_plugin/trunk/1.2/objects/export/test_output/linux/system_test_cheader_expanded_metadata.hapigen_processed --template-path ./objects/export/templates/ivi_based_obsolete_header.h.mako --output-path ./objects/export/test_output/niFakeObsolete.h --template-search-path /P/MI/shared/hapigen/hapigen/export/1.2/1.2.0f0/templates --template-search-path /P/MI/shared/hapigen/hapigen_cheader_plugin/trunk/1.2/objects/export/templates
*/

#ifndef __NIFAKEOBSOLETE_HEADER
#define __NIFAKEOBSOLETE_HEADER

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif


// Values
// Values used in
//     NIFAKE_ATTR_READ_WRITE_COLOR_OBSOLETE, niFake_EnumArrayOutputFunctionObsolete
#define NIFAKE_VAL_RED                                         1                               // 1 (0x1)
#define NIFAKE_VAL_BLUE                                        (NIFAKE_VAL_RED + 1L)           // 2 (0x2)
#define NIFAKE_VAL_YELLOW                                      5                               // 5 (0x5)
#define NIFAKE_VAL_BLACK                                       42                              // 42 (0x2a)

// Attributes
#define NIFAKE_ATTR_READ_WRITE_BOOL_OBSOLETE                   (NIFAKE_ATTR_BASE + 50L)        // 1000050 (0xf4272), ViBoolean
#define NIFAKE_ATTR_READ_WRITE_COLOR_OBSOLETE                  (NIFAKE_ATTR_BASE + 53L)        // 1000053 (0xf4275), ViInt32



// Functions
ViStatus _VI_FUNC niFake_EnumArrayOutputFunctionObsolete(
   ViSession vi,
   ViInt32 numberOfElements,
   ViInt16 anArray[]);

ViStatus _VI_FUNC niFake_DoubleAllTheNums(
   ViSession vi,
   ViInt32 numberCount,
   ViReal64 numbers[]);

ViStatus _VI_FUNC niFake_AcceptListOfDurationsInSeconds(
   ViSession vi,
   ViInt32 count,
   ViReal64 delays[]);

ViStatus _VI_FUNC niFake_ReturnDurationInSeconds(
   ViSession vi,
   ViReal64 timedelta);

ViStatus _VI_FUNC niFake_ReturnListOfDurationsInSeconds(
   ViSession vi,
   ViInt32 numberOfElements,
   ViReal64 timedeltas[]);

ViStatus _VI_FUNC niFake_ImportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 sizeInBytes,
   ViInt8 configuration[]);

ViStatus _VI_FUNC niFake_ExportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 sizeInBytes,
   ViInt8 configuration[]);


// Errors and Warnings


#endif /* __NIFAKEOBSOLETE_HEADER */

