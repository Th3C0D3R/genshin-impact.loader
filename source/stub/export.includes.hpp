/**
 * \brief   export - includes
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

#pragma warning(disable:4005)

//--------------------------------------------------------------------------------------------------

#include <Windows.h>
#include <hidsdi.h>

#pragma comment(lib, "Hid.lib")

//--------------------------------------------------------------------------------------------------

#pragma comment(linker, "/EXPORT:HidD_FlushQueue,@1")
#pragma comment(linker, "/EXPORT:HidD_FreePreparsedData,@2")
#pragma comment(linker, "/EXPORT:HidD_GetAttributes,@3")
#pragma comment(linker, "/EXPORT:HidD_GetConfiguration,@4")
#pragma comment(linker, "/EXPORT:HidD_GetFeature,@5")
#pragma comment(linker, "/EXPORT:HidD_GetHidGuid,@6")
#pragma comment(linker, "/EXPORT:HidD_GetIndexedString,@7")
#pragma comment(linker, "/EXPORT:HidD_GetInputReport,@8")
#pragma comment(linker, "/EXPORT:HidD_GetManufacturerString,@9")
#pragma comment(linker, "/EXPORT:HidD_GetMsGenreDescriptor,@10")
#pragma comment(linker, "/EXPORT:HidD_GetNumInputBuffers,@11")
#pragma comment(linker, "/EXPORT:HidD_GetPhysicalDescriptor,@12")
#pragma comment(linker, "/EXPORT:HidD_GetPreparsedData,@13")
#pragma comment(linker, "/EXPORT:HidD_GetProductString,@14")
#pragma comment(linker, "/EXPORT:HidD_GetSerialNumberString,@15")
#pragma comment(linker, "/EXPORT:HidD_Hello,@16")
#pragma comment(linker, "/EXPORT:HidD_SetConfiguration,@17")
#pragma comment(linker, "/EXPORT:HidD_SetFeature,@18")
#pragma comment(linker, "/EXPORT:HidD_SetNumInputBuffers,@19")
#pragma comment(linker, "/EXPORT:HidD_SetOutputReport,@20")
#pragma comment(linker, "/EXPORT:HidP_GetButtonCaps,@21")
#pragma comment(linker, "/EXPORT:HidP_GetCaps,@22")
#pragma comment(linker, "/EXPORT:HidP_GetData,@23")
#pragma comment(linker, "/EXPORT:HidP_GetExtendedAttributes,@24")
#pragma comment(linker, "/EXPORT:HidP_GetLinkCollectionNodes,@25")
#pragma comment(linker, "/EXPORT:HidP_GetScaledUsageValue,@26")
#pragma comment(linker, "/EXPORT:HidP_GetSpecificButtonCaps,@27")
#pragma comment(linker, "/EXPORT:HidP_GetSpecificValueCaps,@28")
#pragma comment(linker, "/EXPORT:HidP_GetUsageValue,@29")
#pragma comment(linker, "/EXPORT:HidP_GetUsageValueArray,@30")
#pragma comment(linker, "/EXPORT:HidP_GetUsages,@31")
#pragma comment(linker, "/EXPORT:HidP_GetUsagesEx,@32")
#pragma comment(linker, "/EXPORT:HidP_GetValueCaps,@33")
#pragma comment(linker, "/EXPORT:HidP_InitializeReportForID,@34")
#pragma comment(linker, "/EXPORT:HidP_MaxDataListLength,@35")
#pragma comment(linker, "/EXPORT:HidP_MaxUsageListLength,@36")
#pragma comment(linker, "/EXPORT:HidP_SetData,@37")
#pragma comment(linker, "/EXPORT:HidP_SetScaledUsageValue,@38")
#pragma comment(linker, "/EXPORT:HidP_SetUsageValue,@39")
#pragma comment(linker, "/EXPORT:HidP_SetUsageValueArray,@40")
#pragma comment(linker, "/EXPORT:HidP_SetUsages,@41")
#pragma comment(linker, "/EXPORT:HidP_TranslateUsagesToI8042ScanCodes,@42")
#pragma comment(linker, "/EXPORT:HidP_UnsetUsages,@43")
#pragma comment(linker, "/EXPORT:HidP_UsageListDifference,@44")
