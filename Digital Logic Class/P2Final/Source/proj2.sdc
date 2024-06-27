create_clock -name "ADC_CLK_10" -period 100.000ns [get_ports {ADC_CLK_10}]
derive_pll_clocks
derive_clock_uncertainty