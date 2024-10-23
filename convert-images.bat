cd ./res 

:: Convert the latest version of the general tileset first, since all other tilesets will pull from it.
png2asset tiles_general.png -spr8x8 -map -noflip -tiles_only

:: Convert the puzzle tilesets, using the general tileset as the base.
png2asset tiles_gonefishing.png -spr8x8 -map -noflip -source_tileset tiles_general.png -tile_origin 96 -b 255

:: Convert the backgrounds, using the general tileset as source tiles. 
png2asset bkg_title.png -spr8x8 -map -noflip -source_tileset tiles_general.png -tile_origin 96 -b 255
png2asset bkg_bkg_selection.png -spr8x8 -map -noflip -source_tileset tiles_general.png -tile_origin 96 -b 255
png2asset bkg_md_std.png -spr8x8 -map -noflip -maps_only -source_tileset tiles_general.png -b 255

:: Convert the sprites.
png2asset spr_star.png -spr8x8 -noflip -b 255


cd ..