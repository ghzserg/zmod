---
name: Problem [enter details here]
about: Describe the problem in detail
title: 'Problem '
labels: ''
assignees: ghzserg

---

Before asking a question, ask [@zmod_help_bot](http://t.me/zmod_help_bot) and read:
- **[TAR_CONFIG formatting algorithm](https://github.com/ghzserg/zmod/wiki/FAQ_en#help)** - without it, the ticket will not be considered
- [FAQ](https://github.com/ghzserg/zmod/wiki/FAQ_en)
- [Recommendations](https://github.com/ghzserg/zmod/wiki/Recomendations_en)
- [Macro documentation](https://github.com/ghzserg/zmod/wiki/Macros_en)

If you're using any plugins other than recommended, disable them.
If the issue persists, create a ticket. If the issue is caused by the g28_tenz or nopoop plugins, please indicate this in the issue title. [If the issue is caused by the bambufy plugin, please contact the author](https://github.com/function3d/bambufy).

- [ ] I have AD5M
- [ ] I have AD5M PRO
- [ ] I have AD5X

- [X] I work with the native screen
- [ ] I work without a screen
- [ ] I work with Guppyscreen
(replace the space with x inside the brackets)

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

Detailed error description:
Please describe in as much detail as possible what you did, what you planned to get, and what you got.

Attach the config.tar.gz file to this text using the paperclip button below.
Without the config.tar.gz file, the ticket will be automatically closed.
