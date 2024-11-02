cd ./res 

:: Convert the latest version of the general tileset first, since (almost) all other tilesets will pull from it.
png2asset tiles_general.png -map -noflip -tiles_only

:: Convert the puzzle tilesets, using the general tileset as the base.
png2asset tiles_gonefishing.png -map -noflip -tile_origin 96 -b 6

:: Convert the backgrounds, using the general tileset as source tiles. 
png2asset bkg_title.png -source_tileset tiles_general.png -map -noflip -b 2
png2asset bkg_selection.png -source_tileset tiles_general.png -map -noflip -b 2
png2asset bkg_md_std.png -source_tileset tiles_general.png -map -noflip -maps_only

:: Convert the uimap elements, which are typically used for Window functions
png2asset uimap_dialogbox.png -source_tileset tiles_general.png -map -noflip -maps_only
png2asset uimap_select-curtain.png -source_tileset bkg_selection.png -map -noflip -maps_only

:: Convert the sprites.
png2asset spr_star.png -spr8x8 -noflip


cd ..