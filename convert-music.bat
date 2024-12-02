cd ./huge 

:: Convert music tracks according to this format: 
    :: uge2source.exe | infile.uge | -b <bank number> | descriptor | outfile.c

uge2source bgm_howtoplay.uge -b 255 bgm_howtoplay bgm_howtoplay.c
uge2source bgm_selection.uge -b 255 bgm_selection bgm_selection.c
uge2source bgm_title.uge -b 255 bgm_title bgm_title.c

cd ..