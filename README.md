![RichNX](./windows-client/src/SwitchDcrpc.Wpf/RNX.png)

RichNX shows Nintendo Switch activity as Discord Rich Presence.

## Components
- `Sysmodule` (Switch): exposes telemetry via HTTP
- `Windows client` (RichNX): polls `/state` and updates Discord RPC

## Quick Start
1. Copy the sysmodule to Atmosphere:
- `sd:/atmosphere/contents/00FF0000A1B2C3D4/exefs.nsp`
- `sd:/atmosphere/contents/00FF0000A1B2C3D4/flags/boot2.flag`
  
2. Reboot the Switch.
3. Start the Windows client (`RichNX.exe`).
4. Enter your `Switch IP` in RichNX and click `Start`.

## HTTP API
- `GET /state`
- `GET /debug`

Example `/state`:
```json
{
  "service": "RichNX",
  "firmware": "21.2.0",
  "active_program_id": "0x01006F8002326000",
  "active_game": "Animal Crossing New Horizons",
  "battery_percent": 78,
  "is_charging": true,
  "is_docked": true,
  "started_sec": 12,
  "last_update_sec": 20
}
```

## Windows Client
Default values:
- `Port`: `6029`
- `RPC Name`: `Playing on Switch`
- `Poll (ms)`: `2000`

Key features:
- Discord IPC (`discord-ipc-0..9`)
- Title resolving (local list + TitleDB)
- Tray mode + single instance
- Optional GitHub button
- Optional battery status in RPC


## License
GPL-3.0
