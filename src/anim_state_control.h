
#ifndef ANIM_STATE_CONTROL_H
#define ANIM_STATE_CONTROL_H

struct ss_animation_s;
struct entity_s;

/*
 * SURFACE MOVEMENT DIRECTIONS
 */

#define ENT_STAY 0x00000000
#define ENT_MOVE_FORWARD 0x00000001
#define ENT_MOVE_BACKWARD 0x00000002
#define ENT_MOVE_LEFT 0x00000004
#define ENT_MOVE_RIGHT 0x00000008
#define ENT_MOVE_JUMP 0x00000010
#define ENT_MOVE_CROUCH 0x00000020

/*
 *  ====== LARA'S ANIMATIONS ======
 *
 *  NOTE: In case of conflicting animations, there will be tr* prefix inside name.
 *
 *
 *  TR1 AND ABOVE (0-159)
 */
#define TR_ANIMATION_LARA_RUN 0
#define TR_ANIMATION_LARA_WALK_FORWARD 1
#define TR_ANIMATION_LARA_END_WALK_RIGHT 2
#define TR_ANIMATION_LARA_END_WALK_LEFT 3
#define TR_ANIMATION_LARA_WALK_TO_RUN_RIGHT 4
#define TR_ANIMATION_LARA_WALK_TO_RUN_LEFT 5
#define TR_ANIMATION_LARA_STAY_TO_RUN 6
#define TR_ANIMATION_LARA_RUN_TO_WALK_RIGHT 7
#define TR_ANIMATION_LARA_RUN_TO_STAY_LEFT 8
#define TR_ANIMATION_LARA_RUN_TO_WALK_LEFT 9
#define TR_ANIMATION_LARA_RUN_TO_STAY_RIGHT 10
#define TR_ANIMATION_LARA_STAY_SOLID 11                         // Intermediate animation used to reset flags and states.
#define TR_ANIMATION_LARA_TURN_RIGHT_SLOW 12                    // Used once before the fast one if all weapon are in holsters
#define TR_ANIMATION_LARA_TURN_LEFT_SLOW 13                     // Used once before the fast one if all weapon are in holsters
#define TR_ANIMATION_LARA_LANDING_FORWARD_BOTH 14               // Original landing animation in the TR1 betas... But removed
#define TR_ANIMATION_LARA_LANDING_FORWARD_BOTH_CONTINUE 15      // Original landing animation in the TR1 betas... But removed
#define TR_ANIMATION_LARA_JUMPING_FORWARD_RIGHT 16              // OK
#define TR_ANIMATION_LARA_START_FLY_FORWARD_RIGHT 17            // OK
#define TR_ANIMATION_LARA_JUMPING_FORWARD_LEFT 18               // OK
#define TR_ANIMATION_LARA_START_FLY_FORWARD_LEFT 19             // OK
#define TR_ANIMATION_LARA_WALK_FORWARD_BEGIN 20
#define TR_ANIMATION_LARA_WALK_FORWARD_BEGIN_CONTINUE 21
#define TR_ANIMATION_LARA_START_FREE_FALL 22
#define TR_ANIMATION_LARA_FREE_FALL_LONG 23
#define TR_ANIMATION_LARA_LANDING_HARD 24
#define TR_ANIMATION_LARA_LANDING_DEATH 25
#define TR_ANIMATION_LARA_STAY_TO_GRAB 26
#define TR_ANIMATION_LARA_STAY_TO_GRAB_CONTINUE 27
#define TR_ANIMATION_LARA_TRY_HANG_VERTICAL 28
#define TR_ANIMATION_LARA_BEGIN_HANGING_VERTICAL 29
#define TR_ANIMATION_LARA_STOP_HANG_VERTICAL 30
#define TR_ANIMATION_LARA_LANDING_LIGHT 31
#define TR_ANIMATION_LARA_SMASH_JUMP 32
#define TR_ANIMATION_LARA_SMASH_JUMP_CONTINUE 33
#define TR_ANIMATION_LARA_FREE_FALL_FORWARD 34
#define TR_ANIMATION_LARA_FREE_FALL_MIDDLE 35
#define TR_ANIMATION_LARA_FREE_FALL_LONG_NO_HURT 36
#define TR_ANIMATION_LARA_HANG_TO_RELEASE 37                    // Was meant to play when Lara is hanging at a ledge and the player releases the Action key
#define TR_ANIMATION_LARA_STOP_WALK_BACK_RIGHT 38
#define TR_ANIMATION_LARA_STOP_WALK_BACK_LEFT 39
#define TR_ANIMATION_LARA_WALK_BACK 40
#define TR_ANIMATION_LARA_START_WALK_BACK 41
#define TR_ANIMATION_LARA_CLIMB_3CLICK 42
#define TR_ANIMATION_LARA_UNKNOWN2 43                           // Was meant to be used like the 52 but finally it got removed
#define TR_ANIMATION_LARA_ROTATE_RIGHT 44
#define TR_ANIMATION_LARA_JUMPING_FORWARD_TO_FREEFALL 45        // Used after the forward jump if she keeps falling
#define TR_ANIMATION_LARA_FLY_FORWARD_TRY_TO_HANG 46
#define TR_ANIMATION_LARA_ROLL_ALTERNATE 47                     // Unused
#define TR_ANIMATION_LARA_ROLL_END_ALTERNATE 48                 // Unused
#define TR_ANIMATION_LARA_FREE_FALL_NO_HURT 49
#define TR_ANIMATION_LARA_CLIMB_2CLICK 50
#define TR_ANIMATION_LARA_CLIMB_2CLICK_END 51
#define TR_ANIMATION_LARA_CLIMB_2CLICK_END_RUNNING 52           // Used if the player keeps pressing the UP cursor key

#define TR_ANIMATION_LARA_WALL_SMASH_LEFT 53
#define TR_ANIMATION_LARA_WALL_SMASH_RIGHT 54
#define TR_ANIMATION_LARA_RUN_UP_STEP_RIGHT 55
#define TR_ANIMATION_LARA_RUN_UP_STEP_LEFT 56
#define TR_ANIMATION_LARA_WALK_UP_STEP_RIGHT 57
#define TR_ANIMATION_LARA_WALK_UP_STEP_LEFT 58
#define TR_ANIMATION_LARA_WALK_DOWN_LEFT 59
#define TR_ANIMATION_LARA_WALK_DOWN_RIGHT 60
#define TR_ANIMATION_LARA_WALK_DOWN_BACK_LEFT 61
#define TR_ANIMATION_LARA_WALK_DOWN_BACK_RIGHT 62

#define TR_ANIMATION_LARA_PULL_SWITCH_DOWN 63
#define TR_ANIMATION_LARA_PULL_SWITCH_UP 64

#define TR_ANIMATION_LARA_WALK_LEFT 65
#define TR_ANIMATION_LARA_WALK_LEFT_END 66
#define TR_ANIMATION_LARA_WALK_RIGHT 67
#define TR_ANIMATION_LARA_WALK_RIGHT_END 68
#define TR_ANIMATION_LARA_ROTATE_LEFT 69
#define TR_ANIMATION_LARA_SLIDE_FORWARD 70
#define TR_ANIMATION_LARA_SLIDE_FORWARD_END 71
#define TR_ANIMATION_LARA_SLIDE_FORWARD_STOP 72
#define TR_ANIMATION_LARA_STAY_JUMP_SIDES 73
#define TR_ANIMATION_LARA_JUMP_BACK_BEGIN 74
#define TR_ANIMATION_LARA_JUMP_BACK 75
#define TR_ANIMATION_LARA_JUMP_FORWARD_BEGIN 76
#define TR_ANIMATION_LARA_CONTINUE_FLY_FORWARD 77
#define TR_ANIMATION_LARA_JUMP_LEFT_BEGIN 78
#define TR_ANIMATION_LARA_JUMP_LEFT 79
#define TR_ANIMATION_LARA_JUMP_RIGHT_BEGIN 80
#define TR_ANIMATION_LARA_JUMP_RIGHT 81
#define TR_ANIMATION_LARA_LANDING_MIDDLE 82
#define TR_ANIMATION_LARA_FORWARD_TO_FREE_FALL 83
#define TR_ANIMATION_LARA_LEFT_TO_FREE_FALL 84
#define TR_ANIMATION_LARA_RIGHT_TO_FREE_FALL 85

#define TR_ANIMATION_LARA_UNDERWATER_SWIM_FORWARD 86
#define TR_ANIMATION_LARA_UNDERWATER_SWIM_SOLID 87
#define TR_ANIMATION_LARA_RUN_BACK_BEGIN 88
#define TR_ANIMATION_LARA_RUN_BACK 89
#define TR_ANIMATION_LARA_RUN_BACK_END 90
#define TR_ANIMATION_LARA_TRY_HANG_VERTICAL_BEGIN 91              // Native bug: glitchy intermediate animation.
#define TR_ANIMATION_LARA_LANDING_FROM_RUN 92
#define TR_ANIMATION_LARA_FREE_FALL_BACK 93
#define TR_ANIMATION_LARA_FLY_FORWARD_TRY_HANG 94
#define TR_ANIMATION_LARA_TRY_HANG_SOLID 95
#define TR_ANIMATION_LARA_HANG_IDLE 96                            // Main climbing animation... triggers
#define TR_ANIMATION_LARA_CLIMB_ON 97
#define TR_ANIMATION_LARA_FREE_FALL_TO_LONG 98
#define TR_ANIMATION_LARA_FALL_CROUCHING_LANDING 99               // Unused
#define TR_ANIMATION_LARA_FREE_FALL_TO_SIDE_LANDING 100
#define TR_ANIMATION_LARA_FREE_FALL_TO_SIDE_LANDING_ALTERNATE 101 // Maybe it was used at the beginning of a forward jump when the player presses Action? Maybe it was used like this with the original beta anim 73
#define TR_ANIMATION_LARA_CLIMB_ON_END 102
#define TR_ANIMATION_LARA_STAY_IDLE 103
#define TR_ANIMATION_LARA_START_SLIDE_BACKWARD 104
#define TR_ANIMATION_LARA_SLIDE_BACKWARD 105
#define TR_ANIMATION_LARA_SLIDE_BACKWARD_END 106
#define TR_ANIMATION_LARA_UNDERWATER_SWIM_TO_IDLE 107
#define TR_ANIMATION_LARA_UNDERWATER_IDLE 108
#define TR_ANIMATION_LARA_UNDERWARER_IDLE_TO_SWIM 109
#define TR_ANIMATION_LARA_ONWATER_IDLE 110

#define TR_ANIMATION_LARA_CLIMB_OUT_OF_WATER 111
#define TR_ANIMATION_LARA_FREE_FALL_TO_UNDERWATER 112
#define TR_ANIMATION_LARA_ONWATER_DIVE_ALTERNATE 113              // This one is not used
#define TR_ANIMATION_LARA_UNDERWATER_TO_ONWATER 114
#define TR_ANIMATION_LARA_ONWATER_DIVE 115
#define TR_ANIMATION_LARA_ONWATER_SWIM_FORWARD 116
#define TR_ANIMATION_LARA_ONWATER_SWIM_FORWARD_TO_IDLE 117
#define TR_ANIMATION_LARA_ONWATER_IDLE_TO_SWIM 118
#define TR_ANIMATION_LARA_FREE_FALL_TO_UNDERWATER_ALTERNATE 119   // This one is used
#define TR_ANIMATION_LARA_START_OBJECT_MOVING 120
#define TR_ANIMATION_LARA_STOP_OBJECT_MOVING 121
#define TR_ANIMATION_LARA_OBJECT_PULL 122
#define TR_ANIMATION_LARA_OBJECT_PUSH 123
#define TR_ANIMATION_LARA_UNDERWATER_DEATH 124
#define TR_ANIMATION_LARA_AH_FORWARD 125
#define TR_ANIMATION_LARA_AH_BACKWARD 126
#define TR_ANIMATION_LARA_AH_LEFT 127
#define TR_ANIMATION_LARA_AH_RIGHT 128
#define TR_ANIMATION_LARA_UNDERWATER_SWITCH 129
#define TR_ANIMATION_LARA_UNDERWATER_PICKUP 130
#define TR_ANIMATION_LARA_USE_KEY 131
#define TR_ANIMATION_LARA_ONWATER_DEATH 132
#define TR_ANIMATION_LARA_RUN_TO_DIE 133
#define TR_ANIMATION_LARA_USE_PUZZLE 134
#define TR_ANIMATION_LARA_PICKUP 135
#define TR_ANIMATION_LARA_CLIMB_LEFT 136
#define TR_ANIMATION_LARA_CLIMB_RIGHT 137
#define TR_ANIMATION_LARA_STAY_TO_DEATH 138
#define TR_ANIMATION_LARA_SQUASH_BOULDER 139
#define TR_ANIMATION_LARA_ONWATER_IDLE_TO_SWIM_BACK 140
#define TR_ANIMATION_LARA_ONWATER_SWIM_BACK 141
#define TR_ANIMATION_LARA_ONWATER_SWIM_BACK_TO_IDLE 142
#define TR_ANIMATION_LARA_ONWATER_SWIM_LEFT 143
#define TR_ANIMATION_LARA_ONWATER_SWIM_RIGHT 144
#define TR_ANIMATION_LARA_JUMP_TO_DEATH 145
#define TR_ANIMATION_LARA_ROLL_BEGIN 146
#define TR_ANIMATION_LARA_ROLL_CONTINUE 147
#define TR_ANIMATION_LARA_ROLL_END 148
#define TR_ANIMATION_LARA_SPIKED 149
#define TR_ANIMATION_LARA_OSCILLATE_HANG_ON 150
#define TR_ANIMATION_LARA_LANDING_ROLL 151
#define TR_ANIMATION_LARA_FISH_TO_UNDERWATER1 152
#define TR_ANIMATION_LARA_FREE_FALL_FISH 153
#define TR_ANIMATION_LARA_FISH_TO_UNDERWATER2 154
#define TR_ANIMATION_LARA_FREE_FALL_FISH_TO_DEATH 155
#define TR_ANIMATION_LARA_START_FLY_LIKE_FISH_LEFT 156
#define TR_ANIMATION_LARA_START_FLY_LIKE_FISH_RIGHT 157
#define TR_ANIMATION_LARA_FREE_FALL_FISH_START 158
#define TR_ANIMATION_LARA_CLIMB_ON2 159
/*
 * TR2 AND ABOVE (160-216)
 */
#define TR_ANIMATION_LARA_STAND_TO_LADDER 160
#define TR_ANIMATION_LARA_LADDER_UP 161
#define TR_ANIMATION_LARA_LADDER_UP_STOP_RIGHT 162
#define TR_ANIMATION_LARA_LADDER_UP_STOP_LEFT 163
#define TR_ANIMATION_LARA_LADDER_IDLE 164
#define TR_ANIMATION_LARA_LADDER_UP_START 165
#define TR_ANIMATION_LARA_LADDER_DOWN_STOP_LEFT 166
#define TR_ANIMATION_LARA_LADDER_DOWN_STOP_RIGHT 167
#define TR_ANIMATION_LARA_LADDER_DOWN 168
#define TR_ANIMATION_LARA_LADDER_DOWN_START 169
#define TR_ANIMATION_LARA_LADDER_RIGHT 170
#define TR_ANIMATION_LARA_LADDER_LEFT 171
#define TR_ANIMATION_LARA_LADDER_HANG 172
#define TR_ANIMATION_LARA_LADDER_HANG_TO_IDLE 173
#define TR_ANIMATION_LARA_LADDER_TO_STAND 174
// #define TR_ANIMATION_LARA_UNKNOWN5 175                   // Unknown use
#define TR_ANIMATION_LARA_ONWATER_TO_WADE_SHALLOW 176
#define TR_ANIMATION_LARA_WADE 177
#define TR_ANIMATION_LARA_RUN_TO_WADE_LEFT 178
#define TR_ANIMATION_LARA_RUN_TO_WADE_RIGHT 179
#define TR_ANIMATION_LARA_WADE_TO_RUN_LEFT 180
#define TR_ANIMATION_LARA_WADE_TO_RUN_RIGHT 181

#define TR_ANIMATION_LARA_LADDER_BACKFLIP_START 182
#define TR_ANIMATION_LARA_LADDER_BACKFLIP_END 183
#define TR_ANIMATION_LARA_WADE_TO_STAY_RIGHT 184
#define TR_ANIMATION_LARA_WADE_TO_STAY_LEFT 185
#define TR_ANIMATION_LARA_STAY_TO_WADE 186
#define TR_ANIMATION_LARA_LADDER_UP_HANDS 187
#define TR_ANIMATION_LARA_LADDER_DOWN_HANDS 188
#define TR_ANIMATION_LARA_FLARE_THROW 189
#define TR_ANIMATION_LARA_ONWATER_TO_WADE_DEEP 190
#define TR_ANIMATION_LARA_ONWATER_TO_LAND_LOW 191
#define TR_ANIMATION_LARA_UNDERWATER_TO_WADE 192
#define TR_ANIMATION_LARA_ONWATER_TO_WADE 193
#define TR_ANIMATION_LARA_LADDER_TO_HANDS_DOWN 194
#define TR_ANIMATION_LARA_SWITCH_SMALL_DOWN 195
#define TR_ANIMATION_LARA_SWITCH_SMALL_UP 196
#define TR_ANIMATION_LARA_BUTTON_PUSH 197
#define TR_ANIMATION_LARA_UNDERWATER_SWIM_TO_STILL_HUDDLE 198
#define TR_ANIMATION_LARA_UNDERWATER_SWIM_TO_STILL_SPRAWL 199
#define TR_ANIMATION_LARA_UNDERWATER_SWIM_TO_STILL_MEDIUM 200
#define TR_ANIMATION_LARA_LADDER_TO_HANDS_RIGHT 201
#define TR_ANIMATION_LARA_LADDER_TO_HANDS_LEFT 202
#define TR_ANIMATION_LARA_UNDERWATER_ROLL_BEGIN 203
#define TR_ANIMATION_LARA_FLARE_PICKUP 204
#define TR_ANIMATION_LARA_UNDERWATER_ROLL_END 205
#define TR_ANIMATION_LARA_UNDERWATER_FLARE_PICKUP 206
#define TR_ANIMATION_LARA_RUNNING_JUMP_ROLL_BEGIN 207
#define TR_ANIMATION_LARA_SOMERSAULT 208
#define TR_ANIMATION_LARA_RUNNING_JUMP_ROLL_END 209
#define TR_ANIMATION_LARA_STANDING_JUMP_ROLL_BEGIN 210
#define TR_ANIMATION_LARA_STANDING_JUMP_ROLL_END 211
#define TR_ANIMATION_LARA_BACKWARDS_JUMP_ROLL_BEGIN 212
#define TR_ANIMATION_LARA_BACKWARDS_JUMP_ROLL_END 213

#define TR_ANIMATION_LARA_TR2_KICK 214
#define TR_ANIMATION_LARA_TR2_ZIPLINE_GRAB 215
#define TR_ANIMATION_LARA_TR2_ZIPLINE_RIDE 216
#define TR_ANIMATION_LARA_TR2_ZIPLINE_FALL 217

/*
 * TR3 AND ABOVE (214-312)
 */
#define TR_ANIMATION_LARA_TR345_ZIPLINE_GRAB 214
#define TR_ANIMATION_LARA_TR345_ZIPLINE_RIDE 215
#define TR_ANIMATION_LARA_TR345_ZIPLINE_FALL 216
#define TR_ANIMATION_LARA_TR345_STAND_TO_CROUCH 217

#define TR_ANIMATION_LARA_SLIDE_FORWARD_TO_RUN 246      // Slide to run!

#define TR_ANIMATION_LARA_JUMP_FORWARD_BEGIN_TO_GRAB 248
#define TR_ANIMATION_LARA_JUMP_FORWARD_END_TO_GRAB 249
#define TR_ANIMATION_LARA_RUN_TO_GRAB_RIGHT 250
#define TR_ANIMATION_LARA_RUN_TO_GRAB_LEFT 251

#define TR_ANIMATION_LARA_RUN_TO_SPRINT_LEFT 224
#define TR_ANIMATION_LARA_RUN_TO_SPRINT_RIGHT 225
#define TR_ANIMATION_LARA_SPRINT 223
#define TR_ANIMATION_LARA_SPRINT_SLIDE_STAND_RIGHT 226
#define TR_ANIMATION_LARA_SPRINT_SLIDE_STAND_RIGHT_BETA 227     // BETA SPRINT-SLIDE STAND
#define TR_ANIMATION_LARA_SPRINT_SLIDE_STAND_LEFT 228
#define TR_ANIMATION_LARA_SPRINT_SLIDE_STAND_LEFT_BETA 229      // BETA SPRINT-SLIDE STAND
#define TR_ANIMATION_LARA_SPRINT_TO_ROLL_LEFT 230
#define TR_ANIMATION_LARA_SPRINT_TO_ROLL_LEFT_BETA 231          // BETA SPRINT ROLL
#define TR_ANIMATION_LARA_SPRINT_ROLL_LEFT_TO_RUN 232
#define TR_ANIMATION_LARA_SPRINT_TO_ROLL_RIGHT 308
#define TR_ANIMATION_LARA_SPRINT_ROLL_RIGHT_TO_RUN 309
#define TR_ANIMATION_LARA_SPRINT_TO_ROLL_ALTERNATE_BEGIN 240     // Not used natively
#define TR_ANIMATION_LARA_SPRINT_TO_ROLL_ALTERNATE_CONTINUE 241  // Not used natively
#define TR_ANIMATION_LARA_SPRINT_TO_ROLL_ALTERNATE_END 242       // Not used natively
#define TR_ANIMATION_LARA_SPRINT_TO_RUN_LEFT 243
#define TR_ANIMATION_LARA_SPRINT_TO_RUN_RIGHT 244
#define TR_ANIMATION_LARA_SPRINT_TO_CROUCH_LEFT 310
#define TR_ANIMATION_LARA_SPRINT_TO_CROUCH_RIGHT 311

#define TR_ANIMATION_LARA_MONKEY_GRAB 233
#define TR_ANIMATION_LARA_MONKEY_IDLE 234
#define TR_ANIMATION_LARA_MONKEY_FALL 235
#define TR_ANIMATION_LARA_MONKEY_FORWARD 236
#define TR_ANIMATION_LARA_MONKEY_STOP_LEFT 237
#define TR_ANIMATION_LARA_MONKEY_STOP_RIGHT 238
#define TR_ANIMATION_LARA_MONKEY_IDLE_TO_FORWARD_LEFT 239
#define TR_ANIMATION_LARA_MONKEY_IDLE_TO_FORWARD_RIGHT 252
#define TR_ANIMATION_LARA_MONKEY_STRAFE_LEFT 253
#define TR_ANIMATION_LARA_MONKEY_STRAFE_LEFT_END 254
#define TR_ANIMATION_LARA_MONKEY_STRAFE_RIGHT 255
#define TR_ANIMATION_LARA_MONKEY_STRAFE_RIGHT_END 256
#define TR_ANIMATION_LARA_MONKEY_TURN_AROUND 257                 // Use Titak's animation from TREP patch
#define TR_ANIMATION_LARA_MONKEY_TURN_LEFT 271
#define TR_ANIMATION_LARA_MONKEY_TURN_RIGHT 272
#define TR_ANIMATION_LARA_MONKEY_TURN_LEFT_EARLY_END 283
#define TR_ANIMATION_LARA_MONKEY_TURN_LEFT_LATE_END 284
#define TR_ANIMATION_LARA_MONKEY_TURN_RIGHT_EARLY_END 285
#define TR_ANIMATION_LARA_MONKEY_TURN_RIGHT_LATE_END 286


#define TR_ANIMATION_LARA_CROUCH_ROLL_FORWARD_BEGIN 218     // Not used natively
#define TR_ANIMATION_LARA_CROUCH_ROLL_FORWARD_BEGIN_ALTERNATE 247    // Not used
#define TR_ANIMATION_LARA_CROUCH_ROLL_FORWARD_CONTINUE 219  // Not used natively
#define TR_ANIMATION_LARA_CROUCH_ROLL_FORWARD_END 220       // Not used natively
#define TR_ANIMATION_LARA_CROUCH_TO_STAND 221
#define TR_ANIMATION_LARA_CROUCH_IDLE 222
#define TR_ANIMATION_LARA_CROUCH_PREPARE 245
#define TR_ANIMATION_LARA_CROUCH_IDLE_SMASH 265             // Not used natively
#define TR_ANIMATION_LARA_CROUCH_TO_CRAWL_BEGIN 258
#define TR_ANIMATION_LARA_CROUCH_TO_CRAWL_CONTINUE 273
#define TR_ANIMATION_LARA_CROUCH_TO_CRAWL_END 264

#define TR_ANIMATION_LARA_CRAWL_TO_CROUCH_BEGIN 259
#define TR_ANIMATION_LARA_CRAWL_TO_CROUCH_END 274
#define TR_ANIMATION_LARA_CRAWL_FORWARD 260
#define TR_ANIMATION_LARA_CRAWL_IDLE_TO_FORWARD 261
#define TR_ANIMATION_LARA_CRAWL_BACKWARD 276
#define TR_ANIMATION_LARA_CRAWL_IDLE_TO_BACKWARD 275
#define TR_ANIMATION_LARA_CRAWL_IDLE 263
#define TR_ANIMATION_LARA_CRAWL_FORWARD_TO_IDLE_BEGIN_RIGHT 262
#define TR_ANIMATION_LARA_CRAWL_FORWARD_TO_IDLE_END_RIGHT 266
#define TR_ANIMATION_LARA_CRAWL_FORWARD_TO_IDLE_BEGIN_LEFT 267
#define TR_ANIMATION_LARA_CRAWL_FORWARD_TO_IDLE_END_LEFT 268
#define TR_ANIMATION_LARA_CRAWL_BACKWARD_TO_IDLE_BEGIN_RIGHT 277
#define TR_ANIMATION_LARA_CRAWL_BACKWARD_TO_IDLE_END_RIGHT 278
#define TR_ANIMATION_LARA_CRAWL_BACKWARD_TO_IDLE_BEGIN_LEFT 279
#define TR_ANIMATION_LARA_CRAWL_BACKWARD_TO_IDLE_END_LEFT 280
#define TR_ANIMATION_LARA_CRAWL_TURN_LEFT 269
#define TR_ANIMATION_LARA_CRAWL_TURN_LEFT_END 281
#define TR_ANIMATION_LARA_CRAWL_TURN_RIGHT 270
#define TR_ANIMATION_LARA_CRAWL_TURN_RIGHT_END 282

#define TR_ANIMATION_LARA_HANG_TO_CROUCH_BEGIN 287
#define TR_ANIMATION_LARA_HANG_TO_CROUCH_END 288
#define TR_ANIMATION_LARA_CRAWL_TO_HANG_BEGIN 289
#define TR_ANIMATION_LARA_CRAWL_TO_HANG_CONTINUE 290
#define TR_ANIMATION_LARA_CRAWL_TO_HANG_END 302

#define TR_ANIMATION_LARA_CROUCH_PICKUP 291
#define TR_ANIMATION_LARA_CROUCH_PICKUP_FLARE 312
#define TR_ANIMATION_LARA_CRAWL_PICKUP 292           // Not natively used - make it work

#define TR_ANIMATION_LARA_CROUCH_SMASH_FORWARD 293
#define TR_ANIMATION_LARA_CROUCH_SMASH_BACKWARD 294
#define TR_ANIMATION_LARA_CROUCH_SMASH_RIGHT 295
#define TR_ANIMATION_LARA_CROUCH_SMASH_LEFT 296

#define TR_ANIMATION_LARA_CRAWL_SMASH_FORWARD 297
#define TR_ANIMATION_LARA_CRAWL_SMASH_BACKWARD 298
#define TR_ANIMATION_LARA_CRAWL_SMASH_RIGHT 299
#define TR_ANIMATION_LARA_CRAWL_SMASH_LEFT 300

#define TR_ANIMATION_LARA_CRAWL_DEATH 301
#define TR_ANIMATION_LARA_CROUCH_ABORT 303

#define TR_ANIMATION_LARA_RUN_TO_CROUCH_LEFT_BEGIN 304
#define TR_ANIMATION_LARA_RUN_TO_CROUCH_RIGHT_BEGIN 305
#define TR_ANIMATION_LARA_RUN_TO_CROUCH_LEFT_END 306
#define TR_ANIMATION_LARA_RUN_TO_CROUCH_RIGHT_END 307
/*
 * TR4 AND ABOVE (313-444)
 */
#define TR_ANIMATION_LARA_DOOR_OPEN_FORWARD 313
#define TR_ANIMATION_LARA_DOOR_OPEN_BACK 314
#define TR_ANIMATION_LARA_DOOR_KICK 315
#define TR_ANIMATION_LARA_GIANT_BUTTON_PUSH 316
#define TR_ANIMATION_LARA_FLOOR_TRAPDOOR_OPEN 317
#define TR_ANIMATION_LARA_CEILING_TRAPDOOR_OPEN 318
#define TR_ANIMATION_LARA_ROUND_HANDLE_GRAB_CLOCKWISE 319
#define TR_ANIMATION_LARA_ROUND_HANDLE_GRAB_COUNTERCLOCKWISE 320
#define TR_ANIMATION_LARA_COGWHEEL_PULL 321
#define TR_ANIMATION_LARA_COGWHEEL_GRAB 322
#define TR_ANIMATION_LARA_COGWHEEL_UNGRAB 323
#define TR_ANIMATION_LARA_LEVERSWITCH_PUSH 324
#define TR_ANIMATION_LARA_HOLE_GRAB 325
#define TR_ANIMATION_LARA_STAY_TO_POLE_GRAB 326
#define TR_ANIMATION_LARA_POLE_JUMP 327
#define TR_ANIMATION_LARA_POLE_IDLE 328
#define TR_ANIMATION_LARA_POLE_CLIMB_UP 329
#define TR_ANIMATION_LARA_POLE_FALL 330
#define TR_ANIMATION_LARA_JUMP_FORWARD_TO_POLE_GRAB 331
#define TR_ANIMATION_LARA_POLE_TURN_LEFT_BEGIN 332
#define TR_ANIMATION_LARA_POLE_TURN_RIGHT_BEGIN 333
#define TR_ANIMATION_LARA_POLE_IDLE_TO_CLIMB_DOWN 334
#define TR_ANIMATION_LARA_POLE_CLIMB_DOWN 335
#define TR_ANIMATION_LARA_POLE_CLIMB_DOWN_TO_IDLE 336
#define TR_ANIMATION_LARA_JUMP_UP_TO_POLE_GRAB 337
#define TR_ANIMATION_LARA_POLE_CLIMB_UP_INBETWEEN 338
#define TR_ANIMATION_LARA_PULLEY_GRAB 339
#define TR_ANIMATION_LARA_PULLEY_PULL 340
#define TR_ANIMATION_LARA_PULLEY_UNGRAB 341
#define TR_ANIMATION_LARA_POLE_GRAB_TO_STAY 342
// #define TR_ANIMATION_LARA_UNKNOWN8 343
#define TR_ANIMATION_LARA_POLE_TURN_LEFT_END 344
// #define TR_ANIMATION_LARA_UNKNOWN9 345
#define TR_ANIMATION_LARA_POLE_TURN_RIGHT_END 346
#define TR_ANIMATION_LARA_ROUND_HANDLE_PUSH_RIGHT_BEGIN 347
#define TR_ANIMATION_LARA_ROUND_HANDLE_PUSH_RIGHT_CONTINUE 348
#define TR_ANIMATION_LARA_ROUND_HANDLE_PUSH_RIGHT_END 349
#define TR_ANIMATION_LARA_ROUND_HANDLE_PUSH_LEFT_BEGIN 350
#define TR_ANIMATION_LARA_ROUND_HANDLE_PUSH_LEFT_CONTINUE 351
#define TR_ANIMATION_LARA_ROUND_HANDLE_PUSH_LEFT_END 352
#define TR_ANIMATION_LARA_CROUCH_TURN_LEFT 353
#define TR_ANIMATION_LARA_CROUCH_TURN_RIGHT 354
#define TR_ANIMATION_LARA_HANG_AROUND_LEFT_OUTER_BEGIN 355
#define TR_ANIMATION_LARA_HANG_AROUND_LEFT_OUTER_END 356
#define TR_ANIMATION_LARA_HANG_AROUND_RIGHT_OUTER_BEGIN 357
#define TR_ANIMATION_LARA_HANG_AROUND_RIGHT_OUTER_END 358
#define TR_ANIMATION_LARA_HANG_AROUND_LEFT_INNER_BEGIN 359
#define TR_ANIMATION_LARA_HANG_AROUND_LEFT_INNER_END 360
#define TR_ANIMATION_LARA_HANG_AROUND_RIGHT_INNER_BEGIN 361
#define TR_ANIMATION_LARA_HANG_AROUND_RIGHT_INNER_END 362
#define TR_ANIMATION_LARA_LADDER_AROUND_LEFT_OUTER_BEGIN 363
#define TR_ANIMATION_LARA_LADDER_AROUND_LEFT_OUTER_END 364
#define TR_ANIMATION_LARA_LADDER_AROUND_RIGHT_OUTER_BEGIN 365
#define TR_ANIMATION_LARA_LADDER_AROUND_RIGHT_OUTER_END 366
#define TR_ANIMATION_LARA_LADDER_AROUND_LEFT_INNER_BEGIN 367
#define TR_ANIMATION_LARA_LADDER_AROUND_LEFT_INNER_END 368
#define TR_ANIMATION_LARA_LADDER_AROUND_RIGHT_INNER_BEGIN 369
#define TR_ANIMATION_LARA_LADDER_AROUND_RIGHT_INNER_END 370
#define TR_ANIMATION_LARA_MONKEY_TO_ROPE_BEGIN 371
#define TR_ANIMATION_LARA_TRAIN_DEATH 372

#define TR_ANIMATION_LARA_MONKEY_TO_ROPE_END 373
#define TR_ANIMATION_LARA_ROPE_IDLE 374              // Review all rope animations!
#define TR_ANIMATION_LARA_ROPE_DOWN_BEGIN 375
#define TR_ANIMATION_LARA_ROPE_UP 376
#define TR_ANIMATION_LARA_ROPE_IDLE_TO_SWING_SOFT 377                  // Unused
#define TR_ANIMATION_LARA_ROPE_GRAB_TO_FALL 378                        // Unused
#define TR_ANIMATION_LARA_ROPE_JUMP_TO_GRAB 379
#define TR_ANIMATION_LARA_ROPE_IDLE_TO_BACKFLIP 380                    // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_TO_FALL_SEMIFRONT 381             // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_TO_FALL_MIDDLE 382                // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_TO_FALL_BACK 383                  // Unused

#define TR_ANIMATION_LARA_ROPE_IDLE_TO_SWING_SEMIMIDDLE 388            // Unused
#define TR_ANIMATION_LARA_ROPE_IDLE_TO_SWING_HALFMIDDLE 389            // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_TO_FALL_FRONT 390                 // Unused
#define TR_ANIMATION_LARA_ROPE_GRAB_TO_FALL_ALTERNATE 391              // Unused

#define TR_ANIMATION_LARA_ROPE_SWING_FORWARD_SEMIHARD 394              // The only one used!
#define TR_ANIMATION_LARA_ROPE_LADDER_TO_HANDS_DOWN_ALTERNATE 395      // Unused, make it work? (used in the TR4 demo if I'm right?) (then you will need to remove all the StateID changes related to the rope animations)
#define TR_ANIMATION_LARA_ROPE_SWING_BACK_CONTINUE 396                 // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_BACK_END 397                      // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_BACK_BEGIN 398                    // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_FORWARD_SOFT 399                  // Unused

#define TR_ANIMATION_LARA_ROPE_SWING_FORWARD_HARD 404                   // Not found... Uhh, unused
#define TR_ANIMATION_LARA_ROPE_CHANGE_ROPE 405                          // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_TO_TRY_HANG_FRONT2 406             // Not sure it's used?
#define TR_ANIMATION_LARA_ROPE_SWING_TO_TRY_HANG_MIDDLE 407             // Not sure it's used?
#define TR_ANIMATION_LARA_ROPE_SWING_BLOCK 408                          // Unused
#define TR_ANIMATION_LARA_ROPE_SWING_TO_TRY_HANG_SEMIMIDDLE 409         // Not sure it's used?
#define TR_ANIMATION_LARA_ROPE_SWING_TO_TRY_HANG_FRONT3 410             // Not sure it's used?



#define TR_ANIMATION_LARA_DOUBLEDOORS_PUSH 412
#define TR_ANIMATION_LARA_BIG_BUTTON_PUSH 413
#define TR_ANIMATION_LARA_JUMPSWITCH 414
#define TR_ANIMATION_LARA_UNDERWATER_PULLEY 415
#define TR_ANIMATION_LARA_UNDERWATER_DOOR_OPEN 416
#define TR_ANIMATION_LARA_PUSHABLE_PUSH_TO_STAND 417
#define TR_ANIMATION_LARA_PUSHABLE_PULL_TO_STAND 418
#define TR_ANIMATION_LARA_CROWBAR_USE_ON_WALL 419
#define TR_ANIMATION_LARA_CROWBAR_USE_ON_FLOOR 420
#define TR_ANIMATION_LARA_CRAWL_JUMP_DOWN 421
#define TR_ANIMATION_LARA_HARP_PLAY 422
#define TR_ANIMATION_LARA_PUT_TRIDENT 423
#define TR_ANIMATION_LARA_PICKUP_PEDESTAL_HIGH 424
#define TR_ANIMATION_LARA_PICKUP_PEDESTAL_LOW 425
#define TR_ANIMATION_LARA_ROTATE_SENET 426
#define TR_ANIMATION_LARA_TORCH_LIGHT_1 427
#define TR_ANIMATION_LARA_TORCH_LIGHT_2 428
#define TR_ANIMATION_LARA_TORCH_LIGHT_3 429
#define TR_ANIMATION_LARA_TORCH_LIGHT_4 430
#define TR_ANIMATION_LARA_TORCH_LIGHT_5 431
#define TR_ANIMATION_LARA_DETONATOR_USE 432

#define TR_ANIMATION_LARA_CORRECT_POSITION_FRONT 433           // Unused
#define TR_ANIMATION_LARA_CORRECT_POSITION_LEFT 434            // Unused
#define TR_ANIMATION_LARA_CORRECT_POSITION_RIGHT 435           // Unused

#define TR_ANIMATION_LARA_CROWBAR_USE_ON_FLOOR_FAIL 436        // Unused
#define TR_ANIMATION_LARA_tr4_DEATH_MAGIC_tr5_USE_KEYCARD 437  // Unused?
#define TR_ANIMATION_LARA_DEATH_BLOWUP 438
#define TR_ANIMATION_LARA_PICKUP_SARCOPHAGUS 439
#define TR_ANIMATION_LARA_DRAG 440
#define TR_ANIMATION_LARA_BINOCULARS 441
#define TR_ANIMATION_LARA_DEATH_BIG_SCORPION 442
#define TR_ANIMATION_LARA_tr4_DEATH_SETH_tr5_ELEVATOR_SMASH 443
#define TR_ANIMATION_LARA_BEETLE_PUT 444
/*
 * TR5 AND ABOVE (445-473)
 */
#define TR_ANIMATION_LARA_ELEVATOR_RECOVER 443
#define TR_ANIMATION_LARA_DOZY 445
#define TR_ANIMATION_LARA_TIGHTROPE_WALK 446
#define TR_ANIMATION_LARA_TIGHTROPE_WALK_TO_STAND 447
#define TR_ANIMATION_LARA_TIGHTROPE_STAND 448
#define TR_ANIMATION_LARA_TIGHTROPE_WALK_TO_STAND_CAREFUL 449
#define TR_ANIMATION_LARA_TIGHTROPE_STAND_TO_WALK 450
#define TR_ANIMATION_LARA_TIGHTROPE_TURN 451
#define TR_ANIMATION_LARA_TIGHTROPE_LOOSE_LEFT 452
#define TR_ANIMATION_LARA_TIGHTROPE_RECOVER_LEFT 453
#define TR_ANIMATION_LARA_TIGHTROPE_FALL_LEFT 454
#define TR_ANIMATION_LARA_TIGHTROPE_LOOSE_RIGHT 455
#define TR_ANIMATION_LARA_TIGHTROPE_RECOVER_RIGHT 456
#define TR_ANIMATION_LARA_TIGHTROPE_FALL_RIGHT 457
#define TR_ANIMATION_LARA_TIGHTROPE_START 458
#define TR_ANIMATION_LARA_TIGHTROPE_FINISH 459
#define TR_ANIMATION_LARA_DOVESWITCH_TURN 460
#define TR_ANIMATION_LARA_BARS_GRAB 461
#define TR_ANIMATION_LARA_BARS_SWING 462
#define TR_ANIMATION_LARA_BARS_JUMP 463
#define TR_ANIMATION_LARA_LOOT_CABINET 464
#define TR_ANIMATION_LARA_LOOT_DRAWER 465
#define TR_ANIMATION_LARA_LOOT_SHELF 466
#define TR_ANIMATION_LARA_RADIO_BEGIN 467
#define TR_ANIMATION_LARA_RADIO_IDLE 468
#define TR_ANIMATION_LARA_RADIO_END 469
#define TR_ANIMATION_LARA_VALVE_TURN 470
#define TR_ANIMATION_LARA_CROWBAR_USE_ON_WALL2 471
#define TR_ANIMATION_LARA_LOOT_CHEST 472
#define TR_ANIMATION_LARA_LADDER_TO_CROUCH 473

//   ====== LARA'S STATES ======

#define TR_STATE_CURRENT (-1)
#define TR_STATE_LARA_WALK_FORWARD 0
#define TR_STATE_LARA_RUN_FORWARD 1
#define TR_STATE_LARA_STOP 2
#define TR_STATE_LARA_JUMP_FORWARD 3
#define TR_STATE_LARA_POSE 4                // Derived from leaked TOMB.MAP
#define TR_STATE_LARA_RUN_BACK 5
#define TR_STATE_LARA_TURN_RIGHT_SLOW 6
#define TR_STATE_LARA_TURN_LEFT_SLOW 7
#define TR_STATE_LARA_DEATH 8
#define TR_STATE_LARA_FREEFALL 9
#define TR_STATE_LARA_HANG 10
#define TR_STATE_LARA_REACH 11
//#define TR_STATE_LARA_UNUSED2 12
#define TR_STATE_LARA_UNDERWATER_STOP 13
#define TR_STATE_LARA_GRAB_TO_FALL 14
#define TR_STATE_LARA_JUMP_PREPARE 15
#define TR_STATE_LARA_WALK_BACK 16
#define TR_STATE_LARA_UNDERWATER_FORWARD 17
#define TR_STATE_LARA_UNDERWATER_INERTIA 18
#define TR_STATE_LARA_GRABBING 19
#define TR_STATE_LARA_TURN_FAST 20
#define TR_STATE_LARA_WALK_RIGHT 21
#define TR_STATE_LARA_WALK_LEFT 22
#define TR_STATE_LARA_ROLL_BACKWARD 23
#define TR_STATE_LARA_SLIDE_FORWARD 24
#define TR_STATE_LARA_JUMP_BACK 25
#define TR_STATE_LARA_JUMP_LEFT 26
#define TR_STATE_LARA_JUMP_RIGHT 27
#define TR_STATE_LARA_JUMP_UP 28
#define TR_STATE_LARA_FALL_BACKWARD 29
#define TR_STATE_LARA_SHIMMY_LEFT 30
#define TR_STATE_LARA_SHIMMY_RIGHT 31
#define TR_STATE_LARA_SLIDE_BACK 32
#define TR_STATE_LARA_ONWATER_STOP 33
#define TR_STATE_LARA_ONWATER_FORWARD 34
#define TR_STATE_LARA_UNDERWATER_DIVING 35
#define TR_STATE_LARA_PUSHABLE_PUSH 36
#define TR_STATE_LARA_PUSHABLE_PULL 37
#define TR_STATE_LARA_PUSHABLE_GRAB 38
#define TR_STATE_LARA_PICKUP 39
#define TR_STATE_LARA_SWITCH_DOWN 40
#define TR_STATE_LARA_SWITCH_UP 41
#define TR_STATE_LARA_INSERT_KEY 42
#define TR_STATE_LARA_INSERT_PUZZLE 43
#define TR_STATE_LARA_WATER_DEATH 44
#define TR_STATE_LARA_ROLL_FORWARD 45
#define TR_STATE_LARA_BOULDER_DEATH 46
#define TR_STATE_LARA_ONWATER_BACK 47
#define TR_STATE_LARA_ONWATER_LEFT 48
#define TR_STATE_LARA_ONWATER_RIGHT 49
#define TR_STATE_LARA_USE_MIDAS 50          //  Derived from leaked TOMB.MAP
#define TR_STATE_LARA_DIE_MIDAS 51          //  Derived from leaked TOMB.MAP
#define TR_STATE_LARA_SWANDIVE_BEGIN 52
#define TR_STATE_LARA_SWANDIVE_END 53
#define TR_STATE_LARA_HANDSTAND 54
#define TR_STATE_LARA_ONWATER_EXIT 55
#define TR_STATE_LARA_LADDER_IDLE 56
#define TR_STATE_LARA_LADDER_UP 57
#define TR_STATE_LARA_LADDER_LEFT 58
//#define TR_STATE_LARA_UNUSED5 59
#define TR_STATE_LARA_LADDER_RIGHT 60
#define TR_STATE_LARA_LADDER_DOWN 61
//#define TR_STATE_LARA_UNUSED6 62
//#define TR_STATE_LARA_UNUSED7 63
//#define TR_STATE_LARA_UNUSED8 64
#define TR_STATE_LARA_WADE_FORWARD 65
#define TR_STATE_LARA_UNDERWATER_TURNAROUND 66
#define TR_STATE_LARA_FLARE_PICKUP 67
#define TR_STATE_LARA_JUMP_ROLL 68
//#define TR_STATE_LARA_UNUSED10 69
#define TR_STATE_LARA_ZIPLINE_RIDE 70
#define TR_STATE_LARA_CROUCH_IDLE 71
#define TR_STATE_LARA_CROUCH_ROLL 72
#define TR_STATE_LARA_SPRINT 73
#define TR_STATE_LARA_SPRINT_ROLL 74
#define TR_STATE_LARA_MONKEYSWING_IDLE 75
#define TR_STATE_LARA_MONKEYSWING_FORWARD 76
#define TR_STATE_LARA_MONKEYSWING_LEFT 77
#define TR_STATE_LARA_MONKEYSWING_RIGHT 78
#define TR_STATE_LARA_MONKEYSWING_TURNAROUND 79
#define TR_STATE_LARA_CRAWL_IDLE 80
#define TR_STATE_LARA_CRAWL_FORWARD 81
#define TR_STATE_LARA_MONKEYSWING_TURN_LEFT 82
#define TR_STATE_LARA_MONKEYSWING_TURN_RIGHT 83
#define TR_STATE_LARA_CRAWL_TURN_LEFT 84
#define TR_STATE_LARA_CRAWL_TURN_RIGHT 85
#define TR_STATE_LARA_CRAWL_BACK 86
#define TR_STATE_LARA_CLIMB_TO_CRAWL 87
#define TR_STATE_LARA_CRAWL_TO_CLIMB 88
#define TR_STATE_LARA_MISC_CONTROL 89
#define TR_STATE_LARA_ROPE_TURN_LEFT 90
#define TR_STATE_LARA_ROPE_TURN_RIGHT 91
#define TR_STATE_LARA_GIANT_BUTTON_PUSH 92
#define TR_STATE_LARA_TRAPDOOR_FLOOR_OPEN 93
//#define TR_STATE_LARA_UNUSED11 94 - in anim 28 prevents to free -fall - like 1 frame stay IDLE reset
#define TR_STATE_LARA_ROUND_HANDLE 95
#define TR_STATE_LARA_COGWHEEL 96
#define TR_STATE_LARA_LEVERSWITCH_PUSH 97
#define TR_STATE_LARA_HOLE 98
#define TR_STATE_LARA_POLE_IDLE 99
#define TR_STATE_LARA_POLE_UP 100
#define TR_STATE_LARA_POLE_DOWN 101
#define TR_STATE_LARA_POLE_TURN_LEFT 102
#define TR_STATE_LARA_POLE_TURN_RIGHT 103
#define TR_STATE_LARA_PULLEY 104
#define TR_STATE_LARA_CROUCH_TURN_LEFT 105
#define TR_STATE_LARA_CROUCH_TURN_RIGHT 106
#define TR_STATE_LARA_CLIMB_CORNER_LEFT_OUTER 107
#define TR_STATE_LARA_CLIMB_CORNER_RIGHT_OUTER 108
#define TR_STATE_LARA_CLIMB_CORNER_LEFT_INNER 109
#define TR_STATE_LARA_CLIMB_CORNER_RIGHT_INNER 110
#define TR_STATE_LARA_ROPE_IDLE 111
#define TR_STATE_LARA_ROPE_CLIMB_UP 112
#define TR_STATE_LARA_ROPE_CLIMB_DOWN 113
#define TR_STATE_LARA_ROPE_SWING 114
#define TR_STATE_LARA_LADDER_TO_HANDS 115
#define TR_STATE_LARA_POSITION_CORRECTOR 116
#define TR_STATE_LARA_DOUBLEDOORS_PUSH 117
#define TR_STATE_LARA_DOZY 118
#define TR_STATE_LARA_TIGHTROPE_IDLE 119
#define TR_STATE_LARA_TIGHTROPE_TURNAROUND 120
#define TR_STATE_LARA_TIGHTROPE_FORWARD 121
#define TR_STATE_LARA_TIGHTROPE_BALANCING_LEFT 122
#define TR_STATE_LARA_TIGHTROPE_BALANCING_RIGHT 123
#define TR_STATE_LARA_TIGHTROPE_ENTER 124
#define TR_STATE_LARA_TIGHTROPE_EXIT 125
#define TR_STATE_LARA_DOVESWITCH 126
#define TR_STATE_LARA_TIGHTROPE_RESTORE_BALANCE 127
#define TR_STATE_LARA_BARS_SWING 128
#define TR_STATE_LARA_BARS_JUMP 129
//#define TR_STATE_LARA_UNUSED12 130
#define TR_STATE_LARA_RADIO_LISTENING 131
#define TR_STATE_LARA_RADIO_OFF 132
//#define TR_STATE_LARA_UNUSED13 133
//#define TR_STATE_LARA_UNUSED14 134
//#define TR_STATE_LARA_UNUSED15 135
//#define TR_STATE_LARA_UNUSED16 136
#define TR_STATE_LARA_PICKUP_FROM_CHEST 137

//   ====== ANIMATION COMMANDS ======

#define TR_ANIMCOMMAND_SETPOSITION  1
#define TR_ANIMCOMMAND_JUMPDISTANCE 2
#define TR_ANIMCOMMAND_EMPTYHANDS   3
#define TR_ANIMCOMMAND_KILL         4
#define TR_ANIMCOMMAND_PLAYSOUND    5
#define TR_ANIMCOMMAND_PLAYEFFECT   6
#define TR_ANIMCOMMAND_INTERACT     7

//   ====== ANIMATION EFFECTS FLAGS ======

#define TR_ANIMCOMMAND_CONDITION_LAND  0x4000
#define TR_ANIMCOMMAND_CONDITION_WATER 0X8000

//   ====== ANIMATION EFFECTS / FLIPEFFECTS ======

#define TR_EFFECT_CHANGEDIRECTION       0
#define TR_EFFECT_SHAKESCREEN           1
#define TR_EFFECT_PLAYFLOODSOUND        2
#define TR_EFFECT_BUBBLE                3
#define TR_EFFECT_ENDLEVEL              4
#define TR_EFFECT_ACTIVATECAMERA        5
#define TR_EFFECT_ACTIVATEKEY           6
#define TR_EFFECT_ENABLEEARTHQUAKES     7
#define TR_EFFECT_GETCROWBAR            8
#define TR_EFFECT_CURTAINFX             9  // Effect 9 is empty in TR4.
#define TR_EFFECT_PLAYSOUND_TIMERFIELD  10
#define TR_EFFECT_PLAYEXPLOSIONSOUND    11
#define TR_EFFECT_DISABLEGUNS           12
#define TR_EFFECT_ENABLEGUNS            13
#define TR_EFFECT_GETRIGHTGUN           14
#define TR_EFFECT_GETLEFTGUN            15
#define TR_EFFECT_FIRERIGHTGUN          16
#define TR_EFFECT_FIRELEFTGUN           17
#define TR_EFFECT_MESHSWAP1             18
#define TR_EFFECT_MESHSWAP2             19
#define TR_EFFECT_MESHSWAP3             20
#define TR_EFFECT_INV_ON                21 // Effect 21 is unknown at offset 4376F0.
#define TR_EFFECT_INV_OFF               22 // Effect 22 is unknown at offset 437700.
#define TR_EFFECT_HIDEOBJECT            23
#define TR_EFFECT_SHOWOBJECT            24
#define TR_EFFECT_STATUEFX              25 // Effect 25 is empty in TR4.
#define TR_EFFECT_RESETHAIR             26
#define TR_EFFECT_BOILERFX              27 // Effect 27 is empty in TR4.
#define TR_EFFECT_SETFOGCOLOUR          28
#define TR_EFFECT_GHOSTTRAP             29 // Effect 29 is unknown at offset 4372F0
#define TR_EFFECT_LARALOCATION          30
#define TR_EFFECT_CLEARSCARABS          31
#define TR_EFFECT_PLAYSTEPSOUND         32 // Also called FOOTPRINT_FX in TR4 source code.

// Effects 33 - 42 are assigned to FLIP_MAP0-FLIP_MAP9 in TR4 source code,
// but are empty in TR4 binaries.

#define TR_EFFECT_GETWATERSKIN          43
#define TR_EFFECT_REMOVEWATERSKIN       44
#define TR_EFFECT_LARALOCATIONPAD       45
#define TR_EFFECT_KILLALLENEMIES        46

int State_Control_Lara(struct entity_s *ent, struct ss_animation_s *ss_anim);

#endif

