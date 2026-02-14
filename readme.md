# Change background project for omarchy

Because i want to have one command that can add picture to background by one command 

## Usage

```bash 
./addbak <pic_file_name> [<pic_file_name2>]
```

### Arguments
- `pic_file_name` - The primary image file to set as background
- `pic_file_name2` (optional) - A second image file for dual-monitor setups

### Examples

Set a single image as background:
```bash
./addbak wallpaper.png
```

Set different backgrounds for each monitor:
```bash
./addbak wallpaper1.png wallpaper2.png
```

## Supported Formats

The tool supports common image formats including PNG, JPG, JPEG, and WebP.

## Requirements

- hyprland or compatible wayland compositor
- swww or hyprpaper for wallpaper management
- imv or swayimg for image preview (optional)
