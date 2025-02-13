from PIL import Image

# Open two images
image1 = Image.open('./images/bg.jpg')
image2 = Image.open('./images/bg2.jpg')

# Convert both images to RGB and ensure they are the same size
image1 = image1.convert('RGB')
image2 = image2.convert('RGB')
image1 = image1.resize(image2.size)

# Get the pixel data
pixels1 = image1.load()
pixels2 = image2.load()

# Create a new image to store the result
result_image = Image.new('RGB', image1.size)
result_pixels = result_image.load()

# Iterate over each pixel and add the pixel values
width, height = image1.size
for x in range(width):
    for y in range(height):
        r1, g1, b1 = pixels1[x, y]
        r2, g2, b2 = pixels2[x, y]

        # Add pixel values and ensure they do not exceed 255
        new_r = min(r1 + r2, 255)
        new_g = min(g1 + g2, 255)
        new_b = min(b1 + b2, 255)

        # Set the new pixel value
        result_pixels[x, y] = (new_r, new_g, new_b)

# Save the resulting image
result_image.save('./images/modified_image.jpg')
