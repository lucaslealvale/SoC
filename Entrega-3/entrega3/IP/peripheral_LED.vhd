 library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.numeric_std.all;
use work.all;

entity peripheral_LED is
    generic (
        LEN  : natural := 4
    );
    port (
        -- Gloabals
        clk                : in  std_logic                     := '0';             
        reset              : in  std_logic                     := '0';             

        -- I/Os
        LEDs               : out std_logic_vector(LEN - 1 downto 0) := (others => '0');

        -- Avalion Memmory Mapped Slave
        avs_address     : in  std_logic_vector(3 downto 0)  := (others => '0'); 
        avs_read        : in  std_logic                     := '0';             
        avs_readdata    : out std_logic_vector(31 downto 0) := (others => '0'); 
        avs_write       : in  std_logic                     := '0';             
        avs_writedata   : in  std_logic_vector(31 downto 0) := (others => '0')
    );
end entity peripheral_LED;
architecture rtl of peripheral_LED is

component stepmotor is port (
    clk    : in  std_logic;
    en     : in  std_logic;
    dir    : in  std_logic;
    vel    : in  std_logic_vector(1 downto 0);
    phases : out std_logic_vector(3 downto 0));
  end component;
  SIGNAL stepmotor_en, stepmotor_dir : std_logic;
  SIGNAL stepmotor_vel : std_logic_vector(1 downto 0);
  begin
  
  motor: stepmotor port map (clk=>clk, en =>stepmotor_en, dir=>stepmotor_dir,vel => stepmotor_vel, phases => LEDs);
  process(clk)
  begin
    if(rising_edge(clk)) then
        if(avs_address = "0000") then                  -- REG_DATA
            if(avs_write = '1') then
              stepmotor_en <= avs_writedata(0);
              stepmotor_dir <= avs_writedata(1);
              stepmotor_vel <= avs_writedata(3 downto 2);
            end if;

 

            if(avs_read = '1') then
              avs_readdata(0) <= stepmotor_en;
              avs_readdata(1) <= stepmotor_dir;
              avs_readdata(3 downto 2) <= stepmotor_vel;
            end if;
        end if;
    end if;
  end process;

end rtl;