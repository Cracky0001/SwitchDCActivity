# Switch-DCRPC

Komplettlösung für Discord Rich Presence auf der Nintendo Switch:

1. **Sysmodule (Switch-Seite)** liefert den aktuellen Zustand als HTTP-JSON (`/state`)
2. **Windows-Client** pollt diesen Zustand und setzt daraus Discord RPC

## Inhaltsübersicht

- [Projektaufbau](#projektaufbau)
- [End-to-End Datenfluss](#end-to-end-datenfluss)
- [Sysmodule (Switch)](#sysmodule-switch)
- [Windows-Client](#windows-client)
- [Schnellstart](#schnellstart)
- [Troubleshooting](#troubleshooting)

## Projektaufbau

- `source/`, `include/`, `Makefile`  
  Switch-Sysmodule (Atmosphère)
- `scripts/package.ps1`  
  Build + SD-Card Paketstruktur
- `windows-client/`  
  WPF-Desktopclient (`net10.0-windows`)

## End-to-End Datenfluss

1. Sysmodule läuft auf der Switch
2. Sysmodule stellt HTTP-Endpoint bereit (`GET /state`)
3. Windows-Client ruft `/state` zyklisch ab
4. Client löst Spieletitel/Icons auf
5. Client setzt Discord Rich Presence über IPC (`discord-ipc-*`)

## Sysmodule (Switch)

### Aufgaben

- Telemetrie erfassen (z. B. Firmware, aktives Spiel, Program-ID, Zeitwerte)
- HTTP-Endpunkte bereitstellen (`/state`, `/debug`)
- Debug-Log schreiben: `sdmc:/switch/switch-dcrpc/log.log`

### HTTP API

- `GET /state`
- `GET /debug`

Beispielantwort (`/state`):

```json
{
  "service": "switch_dcrpc_idle",
  "firmware": "21.2.0",
  "active_program_id": "0x01006F8002326000",
  "active_game": "Animal Crossing New Horizons",
  "started_sec": 12,
  "last_update_sec": 20,
  "sample_count": 4,
  "last_pm_result": "0x00000000",
  "last_ns_result": "0x00000000"
}
```

### Build + Paket (Switch)

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\package.ps1
```

Typische Ausgabe für SD:

- `dist/sdcard/atmosphere/contents/00FF0000A1B2C3D4/exefs.nsp`
- `dist/sdcard/atmosphere/contents/00FF0000A1B2C3D4/flags/boot2.flag`

## Windows-Client

Vollständige Doku: **`windows-client/README.md`**

Kurzfassung:

- `net10.0-windows` WPF-App
- Single-Instance (zweiter Start fokussiert bestehendes Fenster)
- Tray-Modus mit Hintergrund-Hinweis bei `X`
- Settings: Autostart, Connect-on-startup, GitHub-Button im RPC
- Optionaler Discord-RPC-Button zum Repository

## Schnellstart

1. Switch-Sysmodule bauen/deployen
2. Windows-Client starten
3. Im Client `Switch IP` + `Port` setzen
4. `Start` klicken
5. Discord öffnen und Presence prüfen

## Troubleshooting

- **Discord not connected**
  - Discord Desktop muss laufen
- **Switch endpoint unreachable**
  - IP/Port prüfen, `/state` im Browser testen
- **RPC verschwindet bei Verbindungsproblemen**
  - Gewollt: nach längerer Unerreichbarkeit wird Activity gecleart
- **1/70 VirusTotal Detection**
  - häufig Heuristik/False Positive bei Single-File, Self-Extract, unsignierter EXE

## Lizenz

Lizenzangabe nach Bedarf ergänzen.
