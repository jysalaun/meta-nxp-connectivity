inherit cmake
SRC_URI = "gitsm://github.com/openthread/openthread.git;branch=main;protocol=https"
SRCREV = "4c378f798de53db6070a31edeaabd1158e6e48e3"

# patch files for openthread
SRC_URI += "file://otpatches-081-4c378f7/0001-coex-buff-issue-fix.patch"
SRC_URI += "file://otpatches-081-4c378f7/0002-csl-debug_prints.patch"
SRC_URI += "file://otpatches-081-4c378f7/0003_all_VSC_commands.patch"
SRC_URI += "file://otpatches-081-4c378f7/0006-ot-daemon-release-resources.patch"
SRC_URI += "file://otpatches-081-4c378f7/0019-remove-toggle-reset-pin.patch"
SRC_URI += "file://otpatches-081-4c378f7/0020-lnt-fix-spi-latency.patch"
SRC_URI += "file://otpatches-081-4c378f7/0025-spi-new-design-host.patch"
SRC_URI += "file://otpatches-081-4c378f7/0034-set-default-txpower-on-reset.patch"
SRC_URI += "file://otpatches-081-4c378f7/0036-set-default-rssi-on-reset-for-host.patch"
SRC_URI += "file://otpatches-081-4c378f7/0040-radio-spinel-stream-raw-retry-mechanism.patch"
SRC_URI += "file://otpatches-081-4c378f7/0051-csl-ch-switch-performance-improvement.patch"
SRC_URI += "file://otpatches-081-4c378f7/0057-reset-available-on-rcp-recovery.patch"
SRC_URI += "file://otpatches-081-4c378f7/0060-dualpan-otzb-pan-channel-sense.patch"
SRC_URI += "file://otpatches-081-4c378f7/0061-fct-tool-add-flag-and-fix-build-error.patch"
SRC_URI += "file://otpatches-081-4c378f7/0062-host-handle-power-save-mode-on-ssp-rxd.patch"
SRC_URI += "file://otpatches-081-4c378f7/0068-generic-mfgcmd-support.patch"
SRC_URI += "file://otpatches-081-4c378f7/0070-Specify-MBEDTLS_COMPILER_IS_GCC-inlibrary-common.h.patch"
SRC_URI += "file://otpatches-081-4c378f7/0071-mfgcmd-spifreq-support.patch"
SRC_URI += "file://otpatches-081-4c378f7/0072-Fix-link-error-in-tests-unit-ot-test-ncp-srp_server.patch"

EXTRA_OECMAKE += "-DOT_SLAAC=ON -DOT_ANYCAST_LOCATOR=ON -DOT_BLE_TCAT=ON -DOT_BORDER_AGENT=ON -DOT_BORDER_AGENT_EPSKC=ON -DOT_BORDER_AGENT_ID=ON -DOT_BORDER_ROUTER=ON -DOT_CHANNEL_MANAGER=ON -DOT_CHANNEL_MONITOR=ON -DOT_COAP=ON -DOT_COAPS=ON -DOT_COAP_BLOCK=ON -DOT_COAP_OBSERVE=ON -DOT_COMMISSIONER=ON -DOT_COMPILE_WARNING_AS_ERROR=ON -DOT_COVERAGE=ON -DOT_DATASET_UPDATER=ON -DOT_DHCP6_CLIENT=ON -DOT_DHCP6_SERVER=ON -DOT_DIAGNOSTIC=ON -DOT_DNSSD_SERVER=ON -DOT_DNS_CLIENT=ON -DOT_ECDSA=ON -DOT_HISTORY_TRACKER=ON -DOT_IP6_FRAGM=ON -DOT_JAM_DETECTION=ON -DOT_JOINER=ON -DOT_LOG_LEVEL_DYNAMIC=ON -DOT_MAC_FILTER=ON -DOT_NEIGHBOR_DISCOVERY_AGENT=ON -DOT_NETDATA_PUBLISHER=ON -DOT_NETDIAG_CLIENT=ON -DOT_PING_SENDER=ON -DOT_RCP_RESTORATION_MAX_COUNT=2 -DOT_RCP_TX_WAIT_TIME_SECS=5 -DOT_REFERENCE_DEVICE=ON -DOT_SERVICE=ON -DOT_SNTP_CLIENT=ON -DOT_SRP_CLIENT=ON -DOT_SRP_SERVER=ON -DOT_UPTIME=ON -DOT_TCP=OFF -DOT_LOG_OUTPUT=PLATFORM_DEFINED -DOT_POSIX_MAX_POWER_TABLE=ON -DOT_PLATFORM=posix -DCMAKE_BUILD_TYPE=Release -DOT_COVERAGE=0 -DOT_COMPILE_WARNING_AS_ERROR=0 -DOT_DAEMON=1 -DOT_BACKBONE_ROUTER=1 -DOT_FULL_LOGS=1 -DOT_DUA=1 -DOT_LINK_METRICS_INITIATOR=1 -DOT_LINK_METRICS_SUBJECT=1 -DOT_MLR=1 -DOT_RCP_RESTORATION_MAX_COUNT=5 -DOT_TCP=OFF -DOT_THREAD_VERSION=1.4 -DOT_CHANNEL_MONITOR=0 -DOT_VENDOR_NAME=NXP -DOT_VENDOR_MODEL=IWx12 -DOT_NETDIAG_VENDOR_INFO=0 -DOT_POSIX_PRODUCT_CONFIG=/data/openthread/openthread.conf -DOT_MLE_MAX_CHILDREN=128 -DOT_MAC_CSL_REQUEST_AHEAD_US=16500"

do_install:append() {
    install -d -m 755 ${D}${bindir}
    echo "Renaming ${D}${sbindir}/ot-daemon into ${D}${bindir}/ot-daemon${BIN_NAME_PATTERN}"
    mv ${D}${sbindir}/ot-daemon ${D}${bindir}/ot-daemon${BIN_NAME_PATTERN}
    echo "Renaming ${D}${bindir}/ot-ctl into ${D}${bindir}/ot-client${BIN_NAME_PATTERN}"
    mv ${D}${bindir}/ot-ctl ${D}${bindir}/ot-client${BIN_NAME_PATTERN}
    install -d -m 755 ${D}${sbindir}
    rm -rf ${D}${sbindir}
}
