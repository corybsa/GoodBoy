## blargg
| Test | Result |
|:-|:-|
| cpu_instrs | untested |

---

## mooneye
#### acceptance
| Test | Result |
|:-|:-|
| ld_hl_sp_e_timing | untested |
| add_sp_e_timing | untested |
| call_cc_timing | untested |
| intr_timing | untested |
| boot_regs-mgb | untested |
| halt_ime1_timing | untested |
| interrupts/ie_push | untested |
| push_timing | untested |
| rst_timing | untested |
| boot_regs-sgb | untested |
| boot_regs-sgb2 | untested |
| halt_ime0_nointr_timing | untested |
| call_timing2 | untested |
| boot_div2-S | untested |
| halt_ime1_timing2-GS | untested |
| boot_div-dmgABCmgb | untested |
| boot_div-S | untested |
| halt_ime0_ei | untested |
| reti_timing | untested |
| boot_hwio-dmg0 | untested |
| call_cc_timing2 | untested |
| di_timing-GS | untested |
| boot_hwio-dmgABCmgb | untested |
| div_timing | untested |
| oam_dma_start | untested |
| jp_cc_timing | untested |
| if_ie_registers | untested |
| oam_dma_restart | untested |
| reti_intr_timing | untested |
| pop_timing | untested |
| rapid_di_ei | untested |
| jp_timing | untested |
| oam_dma_timing | untested |
| call_timing | untested |
| ret_cc_timing | untested |
| ret_timing | untested |
| ei_sequence | untested |
| boot_hwio-S | untested |
| ei_timing | untested |
| boot_regs-dmg0 | untested |
| boot_div-dmg0 | untested |
| boot_regs-dmgABC | untested |

###### bits
| Test | Result |
|:-|:-|
| mem_oam | untested |
| reg_f | untested |
| unused_hwio-GS | untested |

###### instr
| Test | Result |
|:-|:-|
| daa | untested |

###### interrupts
| Test | Result |
|:-|:-|
| ie_push | untested |

###### oam_dma
| Test | Result |
|:-|:-|
| basic | untested |
| reg_read | untested |
| sources-GS | untested |

###### ppu
| Test | Result |
|:-|:-|
| hblank_ly_scx_timing-GS | untested |
| intr_1_2_timing | untested |
| intr_2_0_timing | untested |
| intr_2_mode0_timing_sprites | untested |
| intr_2_mode0_timing | untested |
| intr_2_mode3_timing | untested |
| intr_2_oam_ok_timing | untested |
| lcdon_timing-GS | untested |
| lcdon_write_timing-GS | untested |
| stat_irq_onoff | untested |
| stat_lyc_onoff | untested |
| vblank_stat_intr-GS | untested |

###### serial
| Test | Result |
|:-|:-|
| boot_sclk_align-dmgABCmgb | untested |

###### timer
| Test | Result |
|:-|:-|
| rapid_toggle | untested |
| tim01_div_trigger | untested |
| tim00_div_trigger | untested |
| tim10 | untested |
| tim11_div_trigger | untested |
| tim11 | untested |
| tima_write_reloading | untested |
| div_write | untested |
| tim01 | untested |
| tim00 | untested |
| tim10_div_trigger | untested |
| tma_write_reloading | untested |
| tima_reload | untested |

#### emulator-only
###### mbc1
| Test | Result |
|:-|:-|
| ram_64kb | untested |
| rom_16Mb | untested |
| ram_256kb | untested |
| rom_512kb | untested |
| rom_4Mb | untested |
| rom_1Mb | untested |
| rom_8Mb | untested |
| bits_bank2 | untested |
| bits_mode | untested |
| rom_2Mb | untested |
| bits_ramg | untested |
| bits_bank1 | untested |
| multicart_rom_8Mb | untested |

###### mbc2
| Test | Result |
|:-|:-|
| bits_unused | untested |
| ram | untested |
| rom_512kb | untested |
| rom_1Mb | untested |
| rom_2Mb | untested |
| bits_ramg | untested |
| bits_romb | untested |

###### mbc5
| Test | Result |
|:-|:-|
| rom_32Mb | untested |
| rom_16Mb | untested |
| rom_512kb | untested |
| rom_4Mb | untested |
| rom_64Mb | untested |
| rom_1Mb | untested |
| rom_8Mb | untested |
| rom_2Mb | untested |

#### manual-only
| Test | Result |
|:-|:-|
|  sprite_priority  | untested |

#### misc
###### bits
| Test | Result |
|:-|:-|
| boot_div-cgbABCDE | untested |
| boot_div-cgb0 | untested |
| boot_regs-cgb | untested |
| boot_hwio-C | untested |
| boot_regs-A | untested |
| boot_div-A | untested |

###### ppu
| Test | Result |
|:-|:-|
| vblank_stat_intr-C | untested |

#### utils
| Test | Result |
|:-|:-|
| bootrom_dumper | untested |
| dump_boot_hwio | untested |

---

## mealybug tearoom
| Test | Result |
|:-|:-|
| m3_window_timing_wx_0 | untested |
| m3_lcdc_bg_map_change2 | untested |
| m3_wx_4_change_sprites | untested |
| m3_lcdc_obj_size_change | untested |
| m3_lcdc_obj_en_change_variant | untested |
| m3_bgp_change_sprites | untested |
| m3_lcdc_win_map_change2 | untested |
| m3_lcdc_obj_en_change | untested |
| m3_scx_high_5_bits_change2 | untested |
| m3_lcdc_bg_en_change | untested |
| m3_scy_change | untested |
| m3_scx_low_3_bits | untested |
| m3_scx_high_5_bits | untested |
| m3_lcdc_win_en_change_multiple | untested |
| m3_lcdc_bg_en_change2 | untested |
| m2_win_en_toggle | untested |
| m3_wx_6_change | untested |
| m3_lcdc_tile_sel_win_change | untested |
| m3_window_timing | untested |
| m3_lcdc_bg_map_change | untested |
| m3_bgp_change | untested |
| m3_lcdc_tile_sel_win_change2 | untested |
| m3_lcdc_obj_size_change_scx | untested |
| m3_lcdc_win_map_change | untested |
| m3_obp0_change | untested |
| m3_wx_4_change | untested |
| m3_wx_5_change | untested |
| m3_scy_change2 | untested |
| m3_lcdc_tile_sel_change | untested |
| m3_lcdc_tile_sel_change2 | untested |
| m3_lcdc_win_en_change_multiple_wx | untested |
