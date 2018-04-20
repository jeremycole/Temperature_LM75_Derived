/*
 * xmegaDetect.h
 *
 *  Created on: Apr 19, 2018
 *      Author: Pat Deegan
 *
 *  xmegaDetect is part of the LM75-derived temperature sensor project.
 *  Copyright (C) 2018 Pat Deegan, psychogenic.com
 *
 *  Released under the same BSD 3-Clause License and terms
 *  as the library.
 *
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef TEMPERATURE_LM75_DERIVED_SRC_INCLUDES_PLATFORM_XMEGADETECT_H_
#define TEMPERATURE_LM75_DERIVED_SRC_INCLUDES_PLATFORM_XMEGADETECT_H_



#if defined(__AVR_ATxmega16A4__) \
	or defined(__AVR_ATxmega16A4U__) \
	or defined(__AVR_ATxmega16C4__) \
	or defined(__AVR_ATxmega16D4__) \
	or defined(__AVR_ATxmega32A4__) \
	or defined(__AVR_ATxmega32A4U__) \
	or defined(__AVR_ATxmega32C3__) \
	or defined(__AVR_ATxmega32C4__) \
	or defined(__AVR_ATxmega32D3__) \
	or defined(__AVR_ATxmega32D4__) \
	or defined(__AVR_ATxmega8E5__) \
	or defined(__AVR_ATxmega16E5__) \
	or defined(__AVR_ATxmega32E5__) \
	or defined(__AVR_ATxmega64A3__) \
	or defined(__AVR_ATxmega64A3U__) \
	or defined(__AVR_ATxmega64A4U__) \
	or defined(__AVR_ATxmega64B1__) \
	or defined(__AVR_ATxmega64B3__) \
	or defined(__AVR_ATxmega64C3__) \
	or defined(__AVR_ATxmega64D3__) \
	or defined(__AVR_ATxmega64D4__) \
	or defined(__AVR_ATxmega64A1__) \
	or defined(__AVR_ATxmega64A1U__) \
	or defined(__AVR_ATxmega128A3__) \
	or defined(__AVR_ATxmega128A3U__) \
	or defined(__AVR_ATxmega128B1__) \
	or defined(__AVR_ATxmega128B3__) \
	or defined(__AVR_ATxmega128C3__) \
	or defined(__AVR_ATxmega128D3__) \
	or defined(__AVR_ATxmega128D4__) \
	or defined(__AVR_ATxmega192A3__) \
	or defined(__AVR_ATxmega192A3U__) \
	or defined(__AVR_ATxmega192C3__) \
	or defined(__AVR_ATxmega192D3__) \
	or defined(__AVR_ATxmega256A3__) \
	or defined(__AVR_ATxmega256A3U__) \
	or defined(__AVR_ATxmega256A3B__) \
	or defined(__AVR_ATxmega256A3BU__) \
	or defined(__AVR_ATxmega256C3__) \
	or defined(__AVR_ATxmega256D3__) \
	or defined(__AVR_ATxmega384C3__) \
	or defined(__AVR_ATxmega384D3__) \
	or defined(__AVR_ATxmega128A1__) \
	or defined(__AVR_ATxmega128A1U__) \
	or defined(__AVR_ATxmega128A4U__)
	// gots ourselves an xmega!
	#define LM75_XMEGA_AUTODECTED
#warning "XMEGA detected by LM75 lib"
#endif




#endif /* TEMPERATURE_LM75_DERIVED_SRC_INCLUDES_PLATFORM_XMEGADETECT_H_ */
