---
name: Problem [enter details here]
about: Describe the problem in detail
title: 'Problem '
labels: ''
assignees: ghzserg

---

Before asking a question, read:
- **[TAR_CONFIG formatting algorithm](https://github.com/ghzserg/zmod/wiki/FAQ#help)** - without it, the ticket will not be considered
- [FAQ](https://github.com/ghzserg/zmod/wiki/FAQ)
- [Recommendations](https://github.com/ghzserg/zmod/wiki/Recomendations)
- [Macro documentation](https://github.com/ghzserg/zmod/wiki/Macros)

- [ ] I have AD5M
- [ ] I have AD5M PRO
- [ ] I have AD5X

- [X] I work with the native screen
- [ ] I work without a screen
- [ ] I work with Guppyscreen
(replace the space with x inside the brackets)

I uploaded [TAR_CONFIG](https://github.com/ghzserg/zmod/wiki/FAQ#help) to the zmod chat (https://t.me/FF_5M_5M_Pro/408369) or to a file sharing service.
Attach a link to the message with the file or attach the file to this text using the button with a paperclip at the bottom.

If the problem occurs on a specific file with gcode, then attach this file too.
If the problem occurs even when printing a standard cube, then attach the file with the gcode of this cube.

I use the start code:

```
Put your printer start G-code here
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

I wrote the end code:

```
Put your printer end G-code here
END_PRINT
```

Here are my SAVE_ZMOD_DATA parameters:

```
Call GET_ZMOD_DATA and put the output here.
```

Detailed error description:
Please describe in as much detail as possible what you did, what you planned to get, and what you got.
