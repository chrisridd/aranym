/* Joy 2001 */

#include "sysdeps.h"
#include "hardware.h"
#include "cpu_emulation.h"
#include "memory.h"
#include "rtc.h"
#include "parameters.h"

#define CKS_RANGE_START	14
#define CKS_RANGE_END	(14+47)
#define CKS_RANGE_LEN	(CKS_RANGE_END-CKS_RANGE_START+1)
#define CKS_LOC			(14+48)

uae_u8 nvram[64]={48,255,21,255,23,255,1,25,3,33,42,14,112,128,
		0,0,0,0,0,0,0,0,17,46,32,1,255,0,0,56,135,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,31};

/*
int byte15th = (colors & 7) | (80:40) << 3 | (VGA : TV) << 4 | (PAL : NTSC) << 5| overscan << 6 | STcompatible << 7);
int byte14th = VGA:TV ? line doubling : half screen;
*/

RTC::RTC() {
	addr = 0;
}

RTC::~RTC() {
	save();		// save NVRAM file upon exit automatically (should be conditionalized)
}

void RTC::init() {
	// set up the nvram filename
	getConfFilename(ARANYMNVRAM, nvram_filename, sizeof(nvram_filename));

	load();		// load NVRAM file automatically

	if (bx_options.video.monitor != -1) {
		if (bx_options.video.monitor == 0)	// VGA
			nvram[29] |= 32;		// the monitor type should be set on a working copy only
		else
			nvram[29] &= ~32;
	}
	if (bx_options.video.boot_color_depth != -1) {
		int res = nvram[29] & 0x07;
		switch(bx_options.video.boot_color_depth) {
			case 1: res = 0; break;
			case 2: res = 1; break;
			case 4: res = 2; break;
			case 8: res = 3; break;
			case 16: res = 4; break;
		}
		nvram[29] &= ~0x07;
		nvram[29] |= res;		// the booting resolution should be set on a working copy only
	}

	setChecksum();
}

bool RTC::load() {
	bool ret = false;
	FILE *f = fopen(nvram_filename, "rb");
	if (f != NULL) {
		uae_u8 fnvram[CKS_RANGE_LEN];
		if (fread(fnvram, 1, CKS_RANGE_LEN, f) == CKS_RANGE_LEN) {
			memcpy(nvram+CKS_RANGE_START, fnvram, CKS_RANGE_LEN);
			ret = true;
		}
		fclose(f);
	}

	return ret;
}

bool RTC::save() {
	bool ret = false;
	FILE *f = fopen(nvram_filename, "wb");
	if (f != NULL) {
		if (fwrite(nvram+CKS_RANGE_START, 1, CKS_RANGE_LEN, f) == CKS_RANGE_LEN) {
			ret = true;
		}
		fclose(f);
	}

	return ret;
}

static const int HW = 0xff8960;

uae_u8 RTC::handleRead(uaecptr addr) {
	addr -= HW;
	if (addr < 0 || addr > 3)
		return 0;

	switch(addr) {
		case 1: return addr;
		case 3: return getData();
	}

	return 0;
}

void RTC::handleWrite(uaecptr addr, uae_u8 value) {
	addr -= HW;
	if (addr < 0 || addr > 3)
		return;

	switch(addr) {
		case 1: setAddr(value); break;
		case 3: setData(value); break;
	}
}

void RTC::setAddr(uae_u8 value) {
	if (addr < 64)
		addr = value;
}

uae_u8 RTC::getData() {
//	fprintf(stderr, "Reading NVRAM data at %d = %d ($%02x) at %06x\n", addr, nvram[addr], nvram[addr], showPC());
	if (addr <= 9) {
		time_t tim = time(NULL);
		struct tm *curtim = localtime(&tim);	// current time
		switch(addr) {
			case 0:	return curtim->tm_sec;
			case 2: return curtim->tm_min;
			case 4: return curtim->tm_hour;
			case 7: return curtim->tm_mday;
			case 8: return curtim->tm_mon+1;
			case 9: return curtim->tm_year - 68;
			default:return nvram[addr];
		}
	}
	else
		return nvram[addr];
}

void RTC::setData(uae_u8 value) {
//	fprintf(stderr, "Writting NVRAM data at %d = %d ($%02x) at %06x\n", addr, value, value, showPC());
	nvram[addr] = value;
}

/* the checksum is over all bytes except the checksum bytes
 * themselves; these are at the very end */
void RTC::setChecksum()
{
	int i;
	unsigned char sum = 0;
	
	for(i = CKS_RANGE_START; i <= CKS_RANGE_END; ++i)
		sum += nvram[i];
	nvram[CKS_LOC] = ~sum;
	nvram[CKS_LOC+1] = sum;
}
