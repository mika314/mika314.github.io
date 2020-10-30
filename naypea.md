---
Layout: page
title: Naypea
permalink: /naypea/
---

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# Playtest build

[Download Win64](https://cdn.naypea.com/naypea.zip)

The server may be down, or protocol may be incompatible, join my
[Twitch stream](https://www.twitch.tv/mika314) and ask me if it is OK
to playtest.

## Instructions
- Click on the link above and download the file
- Extract all files from the `naypea.zip` file:
  - mouse right click on the file
  - click `Extract All...`
- Open `naypea` directory
- Double click on `naypea.exe` file with Unreal logo on it

Note: antivirus most likely will complain, ignore antivirus warnings.
- Create account and login

Be gentle with the game; it is not stable yet, the server may crash,
the client may crash...

## Features

- Multiplayer
- Voice chat
- Text chat (press `Enter`)
- Blocks placement and removal (similar as in Minecraft)
- Non-player character (sable) placement
- Loading custom 3D models for sable (fbx tested, but other formats also supported but not tested)
- JS scripting for sables
- Sable manual control (click and hold the right mouse button)

## Controls

- `WASD`: for FPS style movement
- `Q` and `E`: move up and down
- `B`: toggle between build mode and play mode
- Mouse right click: (build mode) place block Minecraft style, click
  on sable opens sable UI
- Mouse left click: (build mode) remove block/sable Minecraft style
- Hold right mouse button: (build mode) allow to control sable
- `Enter`: for the chat
- `V`: toggle mute
- `Alt-F4`: to close the game
- `Alt-Enter`: to toggle full-screen and window mode

## Known Issues

- ~~Game sometimes crashes on a model load~~
- ~~Multiple clients freezing the server~~

## JavaScript

Sable script is JavaScript. It has to have `tick()` function with two
parameters on it. First parameter is a reference to the simulation and
second parameter is a reference to the sable.

### sim
- `turn`: turn is number of turns in the game since Unix epoch. Right
now simulation happens 100/sec. turn is a BigInt value.

### sable
- `id`: unique ID
- `loc`: x, y, z location in cm
- `lookUp(deg)`: makes sable look up to `deg` value, negative `deg` makes sable look down
- `moveForward(value)`: moves sable forward `value` cm, negative
  `value` moves sable backward
- `moveRight(value)`: moves sable right `value` cm, negative
  `value` moves sable left
- `moveUp(value)`: moves sable up `value` cm, negative `value` moves sable down
- `rot`: rotation in deg around x, y and z axis (x value should be
  always 0)
- `say(text)`: shows `text` for 5 seconds
- `turnRight(deg)`: turn right `deg` value, negative `deg` turns sable
  left
- `interacts`: array of interacted heroes
  - `id`: unique hero ID
  - `loc`: x, y, z location in cm
  - `rot`: rotation in deg around x, y and z axis (x value should be
  always 0)
  - `username`: hero's username

### Custom vars

It is possible to assign to sim and sable custom variables. Only
number, bool and string are supported.

### Example scripts

#### Welcome to Naypea

Sable says: "Welcome to Naypea" every 10 second.

```javascript
function tick(sim, sable)
{
  if (sim.turn % 1000n == 0)
    sable.say("Welcome to Naypea");
}
```

#### Rotate

Sable rotates.

```javascript
function tick(sim, sable)
{
  sable.turnRight(3);
}
```

#### My name is

Sable on click says: "Hello, [your name]!";

```javascript
function tick(sim, sable)
{
  if (sable.interacts.length > 0)
    sable.say("Hello, " + sable.interacts[0].username + "!");
}
```

#### Cookie clicker

Sable counts number of clicks.

```javascript
function tick(sim, sable)
{
  if (!sable.clicks)
    sable.clicks = 0;
  sable.clicks += sable.interacts.length;
  sable.say("Clicks: " + sable.clicks);
}
```

## Quick Video Tour

[![Alt text](https://img.youtube.com/vi/lxAqNCaRX6w/0.jpg)](https://www.youtube.com/watch?v=lxAqNCaRX6w)
