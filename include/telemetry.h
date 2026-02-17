#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <switch.h>

typedef struct {
    RMutex lock;
    u64 started_sec;
    u64 last_update_sec;
    u64 sample_count;
    char firmware[32];
    u64 active_program_id;
    char active_game[256];
    Result last_pm_result;
    Result last_pminfo_result;
    Result last_ns_result;
    Result last_svc_result;
    u64 last_process_id;
    u32 detection_source; // 0=none, 1=pmdmnt, 2=svc_scan
    u64 next_query_sec;
    u64 pending_program_id;
    u8 pending_match_count;
    bool detection_mode;
    u64 detection_attempt_count;
    u64 detection_success_count;
    u64 detection_fail_count;
    u32 detection_fail_streak;
    u64 detection_last_query_sec;
    u64 detection_last_success_sec;
    u32 battery_percent;
    bool battery_percent_valid;
    bool is_charging;
    bool is_charging_valid;
    bool is_docked;
    bool is_docked_valid;
    u32 dock_detection_source; // 0=none, 1=applet, 2=charger_heuristic
    Result last_psm_charge_result;
    Result last_psm_charger_result;
    Result last_dock_result;
} TelemetryState;

void telemetry_init(TelemetryState* state);
void telemetry_set_firmware(TelemetryState* state, const char* firmware);
void telemetry_update(TelemetryState* state, bool allow_pm_query, bool allow_battery_query, bool allow_dock_query);
void telemetry_build_json(TelemetryState* state, char* out, size_t out_size);
