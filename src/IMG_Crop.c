/**
 * @file IMG_Crop.c
 * @author StanleyHsu (jkyou98@gmail.com)
 * @brief Source code of Image Crop
 * @version 0.1
 * @date 2022-01-13
 * @copyright Copyright (c) 2022
 *
 */
#include "IMG_Crop.h"

#include <stdint.h>
#include <stdio.h>

#include "param.h"

const char *
IMG_Crop_error_str (IMG_CROP_error_t err)
{
  const char *err_str = NULL;
  const char *const IMG_CROP_ERROR_STRS[] = {
    "IMG_CROP_ERROR_OK",
    "IMG_CROP_ERROR_INVARG",
  };
  // Ensure error codes are within the valid array index range
  if (err >= IMG_CROP_ERROR_COUNT)
    {
      goto done;
    }

  err_str = IMG_CROP_ERROR_STRS[err];

done:
  return err_str;
}

static void
ImageCrop_uint8_t (uint8_t *image, uint8_t *crop_image, uint16_t width,
                   uint16_t height, uint16_t anchor_x, uint16_t anchor_y,
                   uint16_t crop_w, uint16_t crop_h)
{
  for (uint16_t i = anchor_y; i < anchor_y + crop_h; ++i)
    {
      for (uint16_t j = anchor_x; j < anchor_x + crop_w; ++j)
        {
          crop_image[(i - anchor_y) * crop_w + (j - anchor_x)]
              = image[i * width + j];
        }
    }
}

IMG_CROP_error_t
IMG_Crop (ImageInfo *IMG, IMG_Crop_param *PARAM)
{
  // pointer check
  if (IMG->image == NULL || IMG->image == NULL)
    return IMG_CROP_ERROR_INVARG;
  if (IMG->bit == 8)
    {
      ImageCrop_uint8_t ((uint8_t *)IMG->image, (uint8_t *)IMG->output_image,
                         IMG->width, IMG->height, PARAM->anchor_x,
                         PARAM->anchor_y, PARAM->crop_w, PARAM->crop_h);
      IMG->update_status = 3;
    }
  return IMG_CROP_ERROR_OK;
}