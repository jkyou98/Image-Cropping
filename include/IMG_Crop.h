/**
 * @file IMG_Crop.h
 * @author StanleyHsu (jkyou98@gmail.com)
 * @brief Function prototypes for image crop
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef IMG_CROP_H_
#define IMG_CROP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include "param.h"
#include <stdint.h>

  /// @brief Error codes for image crop
  typedef enum IMG_CROP_error_e
  {
    /// No error
    IMG_CROP_ERROR_OK = 0,
    /// Invalid arguments (ex.NuLL pointer, parameter overflow)
    IMG_CROP_ERROR_INVARG,
    /// Total # of errors in this list (NOT AN ACTUAL ERROR CODE);
    /// NOTE: that for this to work, it assumes your first error code is value
    /// 0 and you let it naturally increment from there, as is done above,
    /// without explicitly altering any error values above
    IMG_CROP_ERROR_COUNT
  } IMG_CROP_error_t;

  /**
   * @brief      Function to get a printable string from an enum error type
   * @param[in]  err   a valid error code for IMG_Crop module
   * @return     A printable C string corresponding to the error code input
   * above, or NULL if an invalid error code was passed in
   */
  const char *IMG_Crop_error_str (IMG_CROP_error_t err);

  /**
   * @brief Crops image with parameter PARAM
   *
   * @param IMG image struct
   * @param PARAM paramter struct of image cropping
   */
  IMG_CROP_error_t IMG_Crop (ImageInfo *IMG, IMG_Crop_param *PARAM);
#ifdef __cplusplus
}
#endif
#endif