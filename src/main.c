/**
 * @file main.c
 * @author StanleyHsu (jkyou98@gmail.com)
 * @brief This is Demo Code for Image Cropping and use NUCL raw image as
 * example
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BMP.h"
#include "IMG_Crop.h"
#include "RAW.h"
#include "param.h"

#define IMAGE_PATH "res/lena_gray.raw" ///< input image path
#define IMAGE_BIT 8                    ///< image bit
#define WIDTH 512                      ///< image width
#define HEIGHT 512                     ///< image height
#define ANCHOR_X 50                    ///< anchor point of x axis
#define ANCHOR_Y 50                    ///< anchor point of y axis
#define CROP_WIDTH 200                 ///< cropped image width
#define CROP_HEIGHT 200                ///< cropped image height
/**
 * @brief This is the sample code of image cropping. You can use this to test
 * and debug.
 *
 * @return 0
 */
int
main (void)
{

  // buffer allocate

  char filepath[256];
  uint8_t *Input_IMG = (uint8_t *)calloc (WIDTH * HEIGHT, sizeof (uint8_t));
  uint8_t *Output_IMG
      = (uint8_t *)calloc (CROP_WIDTH * CROP_HEIGHT, sizeof (uint8_t));

  // initialize parameters
  ImageInfo Input_IMG_Info = { .image = (void *)Input_IMG,
                               .output_image = (void *)Output_IMG,
                               .width = WIDTH,
                               .height = HEIGHT,
                               .bit = IMAGE_BIT };

  IMG_Crop_param ImageCrop_Param = { .anchor_x = ANCHOR_X,
                                     .anchor_y = ANCHOR_Y,
                                     .crop_w = CROP_WIDTH,
                                     .crop_h = CROP_HEIGHT };

  // Reading Image
  sprintf (filepath, "%s", IMAGE_PATH);
  RAW_READ_uint8_t (filepath, Input_IMG_Info.image, WIDTH, HEIGHT);
  // Crop Image
  IMG_Crop (&Input_IMG_Info, &ImageCrop_Param);
  // Save the result
  RAW_WRITE_uint8_t ("lena_gray_Cropped_W200H200.raw", Output_IMG, CROP_WIDTH,
                     CROP_HEIGHT);
  BMP_W_GRAY_8BIT ("lena_gray_Cropped_W200H200.bmp", Output_IMG, CROP_WIDTH,
                   CROP_HEIGHT);
  // free memory
  free (Input_IMG);
  free (Output_IMG);
  return (0);
}