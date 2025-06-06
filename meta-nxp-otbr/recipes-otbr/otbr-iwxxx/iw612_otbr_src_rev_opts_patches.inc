inherit cmake
SRC_URI = "gitsm://github.com/openthread/ot-br-posix.git;branch=main;protocol=https"
SRCREV = "252be083041f3597c78b41a85939c6799a5942a7"

# patch files for otbr-posix
SRC_URI += "file://otbrpatches-079-d31bcee/otbr-0004-firewall-UART-SPI.patch"
SRC_URI += "file://otbrpatches-079-d31bcee/otbr-0007-support-ot-fct-UART-SPI.patch"
SRC_URI += "file://otbrpatches-079-d31bcee/otbr-0008-Fix-mcpu-cortex-a53-conflicts-with-march-armv8-a-crc-UART-SPI.patch"
SRC_URI += "file://otbrpatches-079-d31bcee/otbr-0009-systemctl-mdns-otbr-options-set-by-otbr-agent-service-UART-SPI.patch"

# patch files for openthread
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0001-coex-buff-issue-fix.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0002-csl-debug_prints.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0003_all_VSC_commands.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0006-ot-daemon-release-resources.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0019-remove-toggle-reset-pin.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0020-lnt-fix-spi-latency.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0025-spi-new-design-host.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0034-set-default-txpower-on-reset.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0036-set-default-rssi-on-reset-for-host.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0040-radio-spinel-stream-raw-retry-mechanism.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0051-csl-ch-switch-performance-improvement.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0057-reset-available-on-rcp-recovery.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0060-dualpan-otzb-pan-channel-sense.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0062-host-handle-power-save-mode-on-ssp-rxd.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0068-generic-mfgcmd-support.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0070-Specify-MBEDTLS_COMPILER_IS_GCC-inlibrary-common.h.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0071-mfgcmd-spifreq-support.patch;patchdir=third_party/openthread/repo/"
SRC_URI += "file://otbrpatches-079-d31bcee/openthread_patches/0072-Fix-link-error-in-tests-unit-ot-test-ncp-srp_server.patch;patchdir=third_party/openthread/repo/"


EXTRA_OECMAKE += "-DCMAKE_CXX_STANDARD=17 -DBUILD_TESTING=OFF -DOTBR_BACKBONE_ROUTER=ON -DOTBR_BORDER_AGENT=ON -DOTBR_BORDER_ROUTING=ON -DOTBR_DBUS=ON -DOTBR_DNSSD_DISCOVERY_PROXY=ON -DOTBR_DUA_ROUTING=ON -DOTBR_INFRA_IF_NAME=eth0 -DOTBR_MDNS=mDNSResponder -DOTBR_REST=ON -DOTBR_SRP_ADVERTISING_PROXY=ON -DOTBR_TREL=ON -DOTBR_WEB=OFF -DOTBR_NAT64=ON -DOT_BACKBONE_ROUTER_MULTICAST_ROUTING=ON -DOT_BORDER_ROUTER=ON -DOT_BORDER_AGENT=ON -DOT_COMMISSIONER=ON -DOT_COAP=ON -DOT_COAP_BLOCK=OFF -DOT_COAP_OBSERVE=ON -DOT_COAPS=ON -DOT_DHCP6_SERVER=ON -DOT_DHCP6_CLIENT=ON -DOT_DNS_CLIENT=ON -DOT_DNSSD_SERVER=ON -DOT_DUA=ON -DOT_ECDSA=ON -DOT_FIREWALL=ON -DOT_FULL_LOGS=ON -DOT_JOINER=ON -DOT_LOG_LEVEL_DYNAMIC=OFF -DOT_LOG_LEVEL=DEBG -DOT_RCP_RESTORATION_MAX_COUNT=5 -DOT_REFERENCE_DEVICE=ON -DOT_SRP_CLIENT=ON -DOT_SRP_SERVER=ON -DOT_THREAD_VERSION=1.4 -DOT_NAT64_BORDER_ROUTING=ON -DOT_NAT64_TRANSLATOR=ON -DOT_VENDOR_NAME=NXP -DOT_VENDOR_MODEL=IWxxx -DOT_NETDIAG_VENDOR_INFO=ON -DOT_POSIX_PRODUCT_CONFIG=/data/openthread/openthread.conf -DOT_MLE_MAX_CHILDREN=128 -DOT_MAC_CSL_REQUEST_AHEAD_US=16500"

addtask do_openthread_repo_revision_reset after do_unpack before do_patch
do_openthread_repo_revision_reset() {
    cd ${S}/third_party/openthread/repo
    echo "Applying on ${S}/third_party/openthread/repo:"
    echo "-> git reset --hard d31bcee81230bd82764838c76c9f291ba64814dd"
    git reset --hard d31bcee81230bd82764838c76c9f291ba64814dd
    result=$?
    if [ ${result} -ne 0 ]; then
        echo "Cannot reset openthread to version d31bcee81230bd82764838c76c9f291ba64814dd, ABORT"
        exit
    fi
}

do_install:append() {
    install -d -m 755 ${D}${sbindir}
    echo "Renaming ${D}${sbindir}/otbr-agent into ${D}${sbindir}/otbr-agent${BIN_NAME_PATTERN}"
    mv ${D}${sbindir}/otbr-agent ${D}${sbindir}/otbr-agent${BIN_NAME_PATTERN}
    echo "Renaming ${D}${sbindir}/ot-ctl into ${D}${sbindir}/ot-ctl${BIN_NAME_PATTERN}"
    mv ${D}${sbindir}/ot-ctl ${D}${sbindir}/ot-ctl${BIN_NAME_PATTERN}

    mv ${D}${systemd_system_unitdir}/imx_otbr_gpiochip_spidev_cfg.sh ${D}${sbindir}
    chmod +x ${D}${sbindir}/imx_otbr_gpiochip_spidev_cfg.sh

    echo "Renaming ${D}${sysconfdir}/default/otbr-agent into ${D}${sysconfdir}/default/otbr-agent${BIN_NAME_PATTERN}"
    mv ${D}${sysconfdir}/default/otbr-agent ${D}${sysconfdir}/default/otbr-agent${BIN_NAME_PATTERN}

    mkdir ${D}${sysconfdir}/init.d
    cp ${S}/script/otbr-firewall ${D}${sysconfdir}/init.d
    chmod +x ${D}${sysconfdir}/init.d/otbr-firewall
    cp ${S}/script/README_firewall.txt ${D}${sysconfdir}/init.d
}
