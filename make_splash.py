#!/usr/bin/env python3

import sys
import os
import struct
from PIL import Image

try:
    im = Image.open(sys.argv[1])
except IndexError:
    print("Usage: make_splash.py <image file> [splash header template]");
    sys.exit(1)

cont = im.tobytes()

splash_array = ["0x" + struct.pack("<I", *struct.unpack(">I", cont[x:x+4])).hex().upper() for x in range(0, len(cont), 4)]

if len(sys.argv) >= 3:
    header_template = sys.argv[2]
else:
    header_template = "boot_splash_screen.inc"

splash_name = os.path.basename(os.path.splitext(im.filename)[0])
header_name, header_ext = os.path.splitext(header_template)
header_name = os.path.basename(header_name)
header_name += "_" + splash_name + header_ext 

with open(header_template) as template:
    with open(header_name, "w") as header:
        header.write(template.read().format(
            int((1280 - im.width)/2),
            int((720 - im.height)/2),
            im.width,
            im.height,
            "{" + ", ".join(splash_array) + "}"
            ))