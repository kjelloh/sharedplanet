# Todo: Consider to study and understand SSD S.M.A.R.T status data logging and interpretation (e.g., by using the command line smartmon tools)?

```#4eb77f14``` *As of 2019-02-18 14:00*

[mail plain/text](mail.txt)

{% raw %}
When shouting for a MAC Pro 6.1 on eBay I encountered the need to get the seller to provide runt-time information on the machine and got to understand that one can view the S.M.A.R.T information logged by the SSD to get a hint of such data.

1) The command line smartmon tool seems to be downloadable from source forge here (<https://sourceforge.net/projects/smartmontools/> )?

2) Consider the Wikipedia page on S.M.A.R.T (<https://en.wikipedia.org/wiki/S.M.A.R.T>. )?

3) Consider the S.M.A.R.T information about the SSD in my MacPro mid 2014 Retina machine?

==&gt; This seems to be the commands I had to issei’s and the information returned by the smartctl tool?

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ /usr/local/sbin/smartctl -a disk1s1  
> smartctl 7.0 2018-12-30 r4883 &#91;Darwin 18.2.0 x86_64&#93; (sf-7.0-1)  
> Copyright (C) 2002-18, Bruce Allen, Christian Franke, [www.smartmontools.org](http://www.smartmontools.org)

> === START OF INFORMATION SECTION ===  
> Model Family: Apple SD/SM/TS...E/F/G SSDs  
> Device Model: APPLE SSD SM1024F  
> Serial Number: S1K6NYAF800700  
> LU WWN Device Id: 5 002538 655584d30  
> Firmware Version: UXM6JA1Q  
> User Capacity: 1,000,555,581,440 bytes &#91;1.00 TB&#93;  
> Sector Sizes: 512 bytes logical, 4096 bytes physical  
> Rotation Rate: Solid State Device  
> Device is: In smartctl database &#91;for details use: -P show&#93;  
> ATA Version is: ATA8-ACS T13/1699-D revision 4c  
> SATA Version is: SATA 3.0, 6.0 Gb/s (current: 6.0 Gb/s)  
> Local Time is: Mon Feb 18 12:20:26 2019 CET  
> SMART support is: Available - device has SMART capability.  
> SMART support is: Enabled

> === START OF READ SMART DATA SECTION ===  
> SMART overall-health self-assessment test result: PASSED

> General SMART Values:  
> Offline data collection status: (0x00) Offline data collection activity  
> was never started.  
> Auto Offline Data Collection: Disabled.  
> Self-test execution status: ( 0) The previous self-test routine completed  
> without error or no self-test has ever  
> been run.  
> Total time to complete Offline  
> data collection:  ( 0) seconds.  
> Offline data collection  
> capabilities:   (0x5f) SMART execute Offline immediate.  
> Auto Offline data collection on/off support.  
> Abort Offline collection upon new  
> command.  
> Offline surface scan supported.  
> Self-test supported.  
> No Conveyance Self-test supported.  
> Selective Self-test supported.  
> SMART capabilities: (0x0003) Saves SMART data before entering  
> power-saving mode.  
> Supports SMART auto save timer.  
> Error logging capability: (0x01) Error logging supported.  
> General Purpose Logging supported.  
> Short self-test routine  
> recommended polling time:   ( 2) minutes.  
> Extended self-test routine  
> recommended polling time:   ( 10) minutes.

> SMART Attributes Data Structure revision number: 40  
> Vendor Specific SMART Attributes with Thresholds:  
> ID# ATTRIBUTE_NAME FLAG VALUE WORST THRESH TYPE UPDATED WHEN_FAILED RAW_VALUE  
> 1 Raw_Read_Error_Rate 0x001a 200 200 000 Old_age Always - 0  
> 5 Reallocated_Sector_Ct 0x0033 100 100 000 Pre-fail Always - 0  
> 9 Power_On_Hours 0x0032 097 097 000 Old_age Always - 11117  
> 12 Power_Cycle_Count 0x0032 084 084 000 Old_age Always - 16026  
> 169 Unknown_Apple_Attrib 0x0013 253 253 010 Pre-fail Always - 7440259103744  
> 173 Wear_Leveling_Count 0x0032 191 191 100 Old_age Always - 47262335021  
> 174 Host_Reads_MiB 0x0022 099 099 000 Old_age Always - 38399889  
> 175 Host_Writes_MiB 0x0022 099 099 000 Old_age Always - 20716730  
> 192 Power-Off_Retract_Count 0x0012 099 099 000 Old_age Always - 56  
> 194 Temperature_Celsius 0x0022 065 065 000 Old_age Always - 35 (Min/Max 11/67)  
> 197 Current_Pending_Sector 0x0022 100 100 000 Old_age Always - 0  
> 199 UDMA_CRC_Error_Count 0x001a 200 200 000 Old_age Always - 0  
> 240 Unknown_SSD_Attribute 0x0022 100 100 000 Old_age Always - 0

> SMART Error Log Version: 1  
> No Errors Logged

> SMART Self-test log structure revision number 1  
> No self-tests have been logged. &#91;To run self-tests, use: smartctl -t&#93;

> SMART Selective self-test log data structure revision number 1  
> SPAN MIN_LBA MAX_LBA CURRENT_TEST_STATUS  
> 1 0 0 Not_testing  
> 2 0 0 Not_testing  
> 3 0 0 Not_testing  
> 4 0 0 Not_testing  
> 5 0 0 Not_testing  
> Selective self-test flags (0x0):  
> After scanning selected spans, do NOT read-scan remainder of disk.  
> If Selective self-test is pending on power-up, resume after 0 minute delay.

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$

==&gt; It seems for some reason my MacBook Pro mid 2014 Retina machine did NOT have the S.M.A.R.T enabled (But I could turn it on using the same smartctl command)?

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ /usr/local/sbin/smartctl -a disk1s1  
> smartctl 7.0 2018-12-30 r4883 &#91;Darwin 18.2.0 x86_64&#93; (sf-7.0-1)  
> Copyright (C) 2002-18, Bruce Allen, Christian Franke, [www.smartmontools.org](http://www.smartmontools.org)

> === START OF INFORMATION SECTION ===  
> Model Family: Apple SD/SM/TS...E/F/G SSDs  
> Device Model: APPLE SSD SM1024F  
> Serial Number: S1K6NYAF800700  
> LU WWN Device Id: 5 002538 655584d30  
> Firmware Version: UXM6JA1Q  
> User Capacity: 1,000,555,581,440 bytes &#91;1.00 TB&#93;  
> Sector Sizes: 512 bytes logical, 4096 bytes physical  
> Rotation Rate: Solid State Device  
> Device is: In smartctl database &#91;for details use: -P show&#93;  
> ATA Version is: ATA8-ACS T13/1699-D revision 4c  
> SATA Version is: SATA 3.0, 6.0 Gb/s (current: 6.0 Gb/s)  
> Local Time is: Mon Feb 18 12:20:05 2019 CET  
> SMART support is: Available - device has SMART capability.  
> SMART support is: Disabled

> SMART Disabled. Use option -s with argument 'on' to enable it.  
> (override with '-T permissive' option)  
> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$ /usr/local/sbin/smartctl -son disk1s1  
> smartctl 7.0 2018-12-30 r4883 &#91;Darwin 18.2.0 x86_64&#93; (sf-7.0-1)  
> Copyright (C) 2002-18, Bruce Allen, Christian Franke, [www.smartmontools.org](http://www.smartmontools.org)

> === START OF ENABLE/DISABLE COMMANDS SECTION ===  
> SMART Enabled.

> Kjell-Olovs-MacBook-Pro-2014:~ kjell-olovhogdahl$

…

4) Consider to analyse the SMART data reported by the seller on eBay of a Mac Pro 6.1 machine I had studied to maybe buy from this eBay account (<https://www.ebay.com/usr/kbalda?_trksid=p2047675.l2559> )?

==&gt; The original eBay link to the Mac Pro 6.1 12 core D700 machine is this one (<https://www.ebay.com/itm/273693071583?ul_noapp=true> )?

## Attachments

- [Mac Pro (Late 2013) 12 core - 2xAMD FirePro D700 6144 MB - 16 GB 1866 MHz DDR3 | eBay.pdf](<Mac Pro (Late 2013) 12 core - 2xAMD FirePro D700 6144 MB - 16 GB 1866 MHz DDR3 eBay.pdf>)

{% endraw %}
