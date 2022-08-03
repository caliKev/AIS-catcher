/*
	Copyright(c) 2021-2022 jvde.github@gmail.com

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <string>

#include "Property.h"

// Copy from ODS spreadsheet
const std::vector<std::string> PropertyDict = {
	"",
	"",
	"class",
	"device",
	"scaled",
	"channel",
	"signalpower",
	"ppm",
	"rxtime",
	"nmea",
	"eta",
	"shiptype_text",
	"aid_type_text",
	// Start ODS input
	"accuracy",
	"addressed",
	"aid_type",
	"airtemp",
	"ais_version",
	"alt",
	"assigned",
	"band",
	"band_a",
	"band_b",
	"beam",
	"callsign",
	"cdepth2",
	"cdepth3",
	"cdir",
	"cdir2",
	"cdir3",
	"channel_a",
	"channel_b",
	"course",
	"course_q",
	"cs",
	"cspeed",
	"cspeed2",
	"cspeed3",
	"dac",
	"data",
	"day",
	"dest_mmsi",
	"dest1",
	"dest2",
	"destination",
	"dewpoint",
	"display",
	"draught",
	"dsc",
	"dte",
	"epfd",
	"epfd_text",
	"fid",
	"gnss",
	"hazard",
	"heading",
	"heading_q",
	"hour",
	"humidity",
	"ice",
	"imo",
	"increment1",
	"increment2",
	"increment3",
	"increment4",
	"interval",
	"lat",
	"length",
	"leveltrend",
	"loaded",
	"lon",
	"maneuver",
	"minute",
	"mmsi",
	"mmsi1",
	"mmsi2",
	"mmsi3",
	"mmsi4",
	"mmsiseq1",
	"mmsiseq2",
	"mmsiseq3",
	"mmsiseq4",
	"model",
	"month",
	"mothership_mmsi",
	"msg22",
	"name",
	"ne_lat",
	"ne_lon",
	"number1",
	"number2",
	"number3",
	"number4",
	"off_position",
	"offset1",
	"offset1_1",
	"offset1_2",
	"offset2",
	"offset2_1",
	"offset3",
	"offset4",
	"partno",
	"power",
	"preciptype",
	"pressure",
	"pressuretend",
	"quiet",
	"radio",
	"raim",
	"regional",
	"repeat",
	"reserved",
	"retransmit",
	"salinity",
	"seastate",
	"second",
	"seqno",
	"serial",
	"ship_type",
	"shipname",
	"shiptype",
	"Spare",
	"speed",
	"speed_q",
	"station_type",
	"status",
	"status_text",
	"sw_lat",
	"sw_lon",
	"swelldir",
	"swellheight",
	"swellperiod",
	"text",
	"timeout1",
	"timeout2",
	"timeout3",
	"timeout4",
	"timestamp",
	"to_bow",
	"to_port",
	"to_starboard",
	"to_stern",
	"turn",
	"txrx",
	"type",
	"type1_1",
	"type1_2",
	"type2_1",
	"vendorid",
	"vin",
	"virtual_aid",
	"visgreater",
	"visibility",
	"waterlevel",
	"watertemp",
	"wavedir",
	"waveheight",
	"waveperiod",
	"wdir",
	"wgust",
	"wgustdir",
	"wspeed",
	"year",
	"zonesize"
};