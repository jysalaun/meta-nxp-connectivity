FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "${@bb.utils.contains_any('MACHINE', "imx93evk imx93evk-iwxxx-matter", 'file://uboot-config/0001-imx93-11x11-evk-ffu-gpio-irq-dtb.cfg', '', d)}"
SRC_URI += "${@bb.utils.contains_any('MACHINE', "imx91evk imx91evk-iwxxx-matter", 'file://uboot-config/0001-imx91-11x11-evk-ffu-gpio-irq-dtb.cfg', '', d)}"

