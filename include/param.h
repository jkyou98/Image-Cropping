/**
 * @file param.h
 * @author StanleyHsu (jkyou98@gmail.com)
 * @brief  Define the stuct of image and parameters of algorithm
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PARAM_H_
#define PARAM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
  /**
   * A structure to represent image basic info.
   */
  typedef struct ImageInfo_t
  {
    /**
     * @name Buffer
     */
    /*@{*/
    void *image;        /**< pointer which point to image buffer */
    void *output_image; /**< pointer which point to output buffer */
    /*@}*/
    /**
     * @name Info
     */
    /*@{*/
    uint16_t width;        /**<  image width */
    uint16_t height;       /**< image height*/
    uint8_t bit;           /**< image bit*/
    uint8_t update_status; /**< 0:original,
                            *1:*image updated,
                            *2:save to *output_image */
    /*@}*/
  } ImageInfo;
  /**
   * A structure to represent IMG_Crop parameter info.
   */
  typedef struct IMG_Crop_param_t
  {
    uint16_t anchor_x; /**< anchor point of x axis*/
    uint16_t anchor_y; /**< anchor point of y axis*/
    uint16_t crop_w;   /**< cropped image width*/
    uint16_t crop_h;   /**< cropped image height*/
  } IMG_Crop_param;

#ifdef __cplusplus
}
#endif
#endif