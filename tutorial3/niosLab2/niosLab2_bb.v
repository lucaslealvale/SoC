
module niosLab2 (
	clk_clk,
	motors_export,
	reset_reset_n,
	switchs_export,
	leds_name);	

	input		clk_clk;
	output	[3:0]	motors_export;
	input		reset_reset_n;
	input	[3:0]	switchs_export;
	output	[3:0]	leds_name;
endmodule
