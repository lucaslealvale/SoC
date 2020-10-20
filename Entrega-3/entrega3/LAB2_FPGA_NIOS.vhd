library IEEE;
use IEEE.std_logic_1164.all;

entity LAB2_FPGA_NIOS is
    port (
        -- Gloabals
        fpga_clk_50        : in  std_logic;             -- clock.clk

        -- I/Os
        fpga_led_pio       : out std_logic_vector(3 downto 0);
		  fpga_switch_pio       : in std_logic_vector(3 downto 0);
		  fpga_motor_pio       : out std_logic_vector(3 downto 0)
  );
end entity LAB2_FPGA_NIOS;

architecture rtl of LAB2_FPGA_NIOS is

component niosLab2 is port (
  clk_clk       : in  std_logic                    := 'X'; -- clk
  reset_reset_n : in  std_logic                    := 'X'; -- reset_n
  switchs_export: in std_logic_vector(3 downto 0); 
  motors_export	 : out std_logic_vector(3 downto 0);
  leds_name   : out std_logic_vector(3 downto 0)         -- export
  
);
end component niosLab2;

begin

u0 : component niosLab2 port map (
  clk_clk       => fpga_clk_50,    --  clk.clk
  reset_reset_n => '1',            --  reset.reset_n
  leds_name   => fpga_motor_pio,    --  leds.export
  switchs_export=> fpga_switch_pio,
  motors_export	 => fpga_led_pio
);

end rtl;
