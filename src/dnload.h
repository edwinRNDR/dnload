#ifndef DNLOAD_H
#define DNLOAD_H

/** \file
 * \brief Dynamic loader header stub.
 *
 * This file was automatically generated by 'dnload.py'.
 */

#if defined(WIN32)
/** \cond */
#define _USE_MATH_DEFINES
#define NOMINMAX
/** \endcond */
#else
/** \cond */
#define GL_GLEXT_PROTOTYPES
/** \endcond */
#endif

#if defined(__cplusplus)
#include <cmath>
#include <cstdio>
#include <cstdlib>
#else
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#endif

#if defined(DNLOAD_VIDEOCORE)
#include "bcm_host.h"
#include "EGL/egl.h"
#endif

#if defined(USE_LD)
#if defined(WIN32)
#include "windows.h"
#include "GL/glew.h"
#include "GL/glu.h"
#elif defined(__APPLE__)
#include "GL/glew.h"
#include <OpenGL/glu.h>
#else
#if defined(DNLOAD_GLESV2)
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#else
#include "GL/glew.h"
#include "GL/glu.h"
#endif
#endif
#else
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <OpenGL/glu.h>
#else
#if defined(DNLOAD_GLESV2)
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#else
#include "GL/gl.h"
#include "GL/glext.h"
#include "GL/glu.h"
#endif
#endif
#endif

#include "SDL.h"

#if defined(SDL_INIT_EVERYTHING) && defined(__APPLE__) 
#define DNLOAD_MAIN SDL_main
#else
#define DNLOAD_MAIN main
#endif

/** Macro stringification helper (adds indirection). */
#define DNLOAD_MACRO_STR_HELPER(op) #op
/** Macro stringification. */
#define DNLOAD_MACRO_STR(op) DNLOAD_MACRO_STR_HELPER(op)

#if defined(DNLOAD_GLESV2)
/** Apientry definition (OpenGL ES 2.0). */
#define DNLOAD_APIENTRY GL_APIENTRY
#else
/** Apientry definition (OpenGL). */
#define DNLOAD_APIENTRY GLAPIENTRY
#endif

#if (defined(_LP64) && _LP64) || (defined(__LP64__) && __LP64__)
/** Size of pointer in bytes (64-bit). */
#define DNLOAD_POINTER_SIZE 8
#else
/** Size of pointer in bytes (32-bit). */
#define DNLOAD_POINTER_SIZE 4
#endif

#if !defined(USE_LD)
/** Error string for when assembler exit procedure is not available. */
#define DNLOAD_ASM_EXIT_ERROR "no assembler exit procedure defined for current operating system or architecture"
/** Perform exit syscall in assembler. */
static void asm_exit(void)
{
#if !defined(DNLOAD_NO_DEBUGGER_TRAP) && (defined(__x86_64__) || defined(__i386__))
  asm("int $0x3" : /* no output */ : /* no input */ : /* no clobber */);
#elif defined(__x86_64__)
#if defined(__FreeBSD__)
  asm_exit() asm("syscall" : /* no output */ : "a"(1) : /* no clobber */);
#elif defined(__linux__)
  asm_exit() asm("syscall" : /* no output */ : "a"(60) : /* no clobber */);
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
#elif defined(__i386__)
#if defined(__FreeBSD__) || defined(__linux__)
  asm("int $0x80" : /* no output */ : "a"(1) : /* no clobber */);
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
#elif defined(__arm__)
#if defined(__linux__)
  register int r7 asm("r7") = 1;
  asm("swi #0" : /* no output */ : "r"(r7) : /* no clobber */);
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
}
#endif

#if defined(USE_LD)
/** \cond */
#define dnload_glUseProgramStages glUseProgramStages
#define dnload_glBindProgramPipeline glBindProgramPipeline
#define dnload_SDL_GL_SwapWindow SDL_GL_SwapWindow
#define dnload_SDL_PauseAudio SDL_PauseAudio
#define dnload_SDL_OpenAudio SDL_OpenAudio
#define dnload_SDL_CreateWindow SDL_CreateWindow
#define dnload_SDL_PollEvent SDL_PollEvent
#define dnload_SDL_Init SDL_Init
#define dnload_glGenProgramPipelines glGenProgramPipelines
#define dnload_SDL_Quit SDL_Quit
#define dnload_glCreateShaderProgramv glCreateShaderProgramv
#define dnload_SDL_ShowCursor SDL_ShowCursor
#define dnload_glProgramUniform3fv glProgramUniform3fv
#define dnload_glRects glRects
#define dnload_SDL_GL_CreateContext SDL_GL_CreateContext
/** \endcond */
#else
/** \cond */
#define dnload_glUseProgramStages g_symbol_table.glUseProgramStages
#define dnload_glBindProgramPipeline g_symbol_table.glBindProgramPipeline
#define dnload_SDL_GL_SwapWindow g_symbol_table.SDL_GL_SwapWindow
#define dnload_SDL_PauseAudio g_symbol_table.SDL_PauseAudio
#define dnload_SDL_OpenAudio g_symbol_table.SDL_OpenAudio
#define dnload_SDL_CreateWindow g_symbol_table.SDL_CreateWindow
#define dnload_SDL_PollEvent g_symbol_table.SDL_PollEvent
#define dnload_SDL_Init g_symbol_table.SDL_Init
#define dnload_glGenProgramPipelines g_symbol_table.glGenProgramPipelines
#define dnload_SDL_Quit g_symbol_table.SDL_Quit
#define dnload_glCreateShaderProgramv g_symbol_table.glCreateShaderProgramv
#define dnload_SDL_ShowCursor g_symbol_table.SDL_ShowCursor
#define dnload_glProgramUniform3fv g_symbol_table.glProgramUniform3fv
#define dnload_glRects g_symbol_table.glRects
#define dnload_SDL_GL_CreateContext g_symbol_table.SDL_GL_CreateContext
/** \endcond */
/** \brief Symbol table structure.
 *
 * Contains all the symbols required for dynamic linking.
 */
static struct SymbolTableStruct
{
  void (DNLOAD_APIENTRY *glUseProgramStages)(GLuint, GLbitfield, GLuint);
  void (DNLOAD_APIENTRY *glBindProgramPipeline)(GLuint);
  void (*SDL_GL_SwapWindow)(SDL_Window*);
  void (*SDL_PauseAudio)(int);
  int (*SDL_OpenAudio)(SDL_AudioSpec*, SDL_AudioSpec*);
  SDL_Window* (*SDL_CreateWindow)(const char*, int, int, int, int, Uint32);
  int (*SDL_PollEvent)(SDL_Event*);
  int (*SDL_Init)(Uint32);
  void (DNLOAD_APIENTRY *glGenProgramPipelines)(GLsizei, GLuint*);
  void (*SDL_Quit)(void);
  GLuint (DNLOAD_APIENTRY *glCreateShaderProgramv)(GLenum, GLsizei, const char**);
  int (*SDL_ShowCursor)(int);
  void (DNLOAD_APIENTRY *glProgramUniform3fv)(GLuint, GLint, GLsizei, const GLfloat*);
  void (DNLOAD_APIENTRY *glRects)(GLshort, GLshort, GLshort, GLshort);
  SDL_GLContext (*SDL_GL_CreateContext)(SDL_Window*);
} g_symbol_table =
{
  (void (DNLOAD_APIENTRY *)(GLuint, GLbitfield, GLuint))0x212d8ad7,
  (void (DNLOAD_APIENTRY *)(GLuint))0x2386bc04,
  (void (*)(SDL_Window*))0x295bfb59,
  (void (*)(int))0x29f14a4,
  (int (*)(SDL_AudioSpec*, SDL_AudioSpec*))0x46fd70c8,
  (SDL_Window* (*)(const char*, int, int, int, int, Uint32))0x4fbea370,
  (int (*)(SDL_Event*))0x64949d97,
  (int (*)(Uint32))0x70d6574,
  (void (DNLOAD_APIENTRY *)(GLsizei, GLuint*))0x75e35418,
  (void (*)(void))0x7eb657f3,
  (GLuint (DNLOAD_APIENTRY *)(GLenum, GLsizei, const char**))0xa4fd03d8,
  (int (*)(int))0xb88bf697,
  (void (DNLOAD_APIENTRY *)(GLuint, GLint, GLsizei, const GLfloat*))0xc969d24e,
  (void (DNLOAD_APIENTRY *)(GLshort, GLshort, GLshort, GLshort))0xd419e20a,
  (SDL_GLContext (*)(SDL_Window*))0xdba45bd,
};
#endif

#if defined(USE_LD)
/** \cond */
#define dnload()
/** \endcond */
#else
#include <stdint.h>
/** \brief SDBM hash function.
 *
 * \param op String to hash.
 * \return Full hash.
 */
static uint32_t sdbm_hash(const uint8_t *op)
{
  uint32_t ret = 0;
  for(;;)
  {
    uint32_t cc = *op++;
    if(!cc)
    {
      return ret;
    }
    ret = ret * 65599 + cc;
  }
}
#if defined(__FreeBSD__)
#include <sys/link_elf.h>
#elif defined(__linux__)
#include <link.h>
#else
#error "no elf header location known for current platform"
#endif
#if (8 == DNLOAD_POINTER_SIZE)
/** Elf header type. */
typedef Elf64_Ehdr dnload_elf_ehdr_t;
/** Elf program header type. */
typedef Elf64_Phdr dnload_elf_phdr_t;
/** Elf dynamic structure type. */
typedef Elf64_Dyn dnload_elf_dyn_t;
/** Elf symbol table entry type. */
typedef Elf64_Sym dnload_elf_sym_t;
/** Elf dynamic structure tag type. */
typedef Elf64_Sxword dnload_elf_tag_t;
#else
/** Elf header type. */
typedef Elf32_Ehdr dnload_elf_ehdr_t;
/** Elf program header type. */
typedef Elf32_Phdr dnload_elf_phdr_t;
/** Elf dynamic structure type. */
typedef Elf32_Dyn dnload_elf_dyn_t;
/** Elf symbol table entry type. */
typedef Elf32_Sym dnload_elf_sym_t;
/** Elf dynamic structure tag type. */
typedef Elf32_Sword dnload_elf_tag_t;
#endif
/** \brief ELF base address. */
#define ELF_BASE_ADDRESS 0x400000
/** \brief Get dynamic section element by tag.
 *
 * \param dyn Dynamic section.
 * \param tag Tag to look for.
 * \return Pointer to dynamic element.
 */
static const dnload_elf_dyn_t* elf_get_dynamic_element_by_tag(const void *dyn, dnload_elf_tag_t tag)
{
  const dnload_elf_dyn_t *dynamic = (const dnload_elf_dyn_t*)dyn;
  do {
    ++dynamic; // First entry in PT_DYNAMIC is probably nothing important.
#if defined(__linux__) && defined(DNLOAD_SAFE_SYMTAB_HANDLING)
    if(0 == dynamic->d_tag)
    {
      return NULL;
    }
#endif
  } while(dynamic->d_tag != tag);
  return dynamic;
}
#if defined(DNLOAD_NO_FIXED_R_DEBUG_ADDRESS) || defined(DNLOAD_SAFE_SYMTAB_HANDLING)
/** \brief Get the address associated with given tag in a dynamic section.
 *
 * \param dyn Dynamic section.
 * \param tag Tag to look for.
 * \return Address matching given tag.
 */
static const void* elf_get_dynamic_address_by_tag(const void *dyn, dnload_elf_tag_t tag)
{
  const dnload_elf_dyn_t *dynamic = elf_get_dynamic_element_by_tag(dyn, tag);
#if defined(__linux__) && defined(DNLOAD_SAFE_SYMTAB_HANDLING)
  if(NULL == dynamic)
  {
    return NULL;
  }
#endif
  return (const void*)dynamic->d_un.d_ptr;
}
#endif
#if !defined(DNLOAD_NO_FIXED_R_DEBUG_ADDRESS)
/** Link map address, fixed location in ELF headers. */
extern const struct r_debug *dynamic_r_debug;
#endif
/** \brief Get the program link map.
 *
 * \return Link map struct.
 */
static const struct link_map* elf_get_link_map()
{
#if defined(DNLOAD_NO_FIXED_R_DEBUG_ADDRESS)
  // ELF header is in a fixed location in memory.
  // First program header is located directly afterwards.
  const dnload_elf_ehdr_t *ehdr = (const dnload_elf_ehdr_t*)ELF_BASE_ADDRESS;
  const dnload_elf_phdr_t *phdr = (const dnload_elf_phdr_t*)((size_t)ehdr + (size_t)ehdr->e_phoff);
  do {
    ++phdr; // Dynamic header is probably never first in PHDR list.
  } while(phdr->p_type != PT_DYNAMIC);
  // Find the debug entry in the dynamic header array.
  {
    const struct r_debug *debug = (const struct r_debug*)elf_get_dynamic_address_by_tag((const void*)phdr->p_vaddr, DT_DEBUG);
    return debug->r_map;
  }
#else
  return dynamic_r_debug->r_map;
#endif
}
/** \brief Return pointer from link map address.
 *
 * \param lmap Link map.
 * \param ptr Pointer in this link map.
 */
static const void* elf_transform_dynamic_address(const struct link_map *lmap, const void *ptr)
{
#if defined(__linux__)
  // Addresses may also be absolute.
  if(ptr >= (void*)(size_t)lmap->l_addr)
  {
    return ptr;
  }
#endif
  return (uint8_t*)ptr + (size_t)lmap->l_addr;
}
#if defined(DNLOAD_SAFE_SYMTAB_HANDLING)
/** \brief Get address of one dynamic section corresponding to given library.
 *
 * \param lmap Link map.
 * \param tag Tag to look for.
 * \return Pointer to given section or NULL.
 */
static const void* elf_get_library_dynamic_section(const struct link_map *lmap, dnload_elf_tag_t tag)
{
  return elf_transform_dynamic_address(lmap, elf_get_dynamic_address_by_tag(lmap->l_ld, tag));
}
#endif
/** \brief Find a symbol in any of the link maps.
 *
 * Should a symbol with name matching the given hash not be present, this function will happily continue until
 * we crash. Size-minimal code has no room for error checking.
 *
 * \param hash Hash of the function name string.
 * \return Symbol found.
 */
static void* dnload_find_symbol(uint32_t hash)
{
  const struct link_map* lmap = elf_get_link_map();
#if defined(__linux__) && (8 == DNLOAD_POINTER_SIZE)
  // On 64-bit Linux, the second entry is not usable.
  lmap = lmap->l_next;
#endif
  for(;;)
  {
    // First entry is this object itself, safe to advance first.
    lmap = lmap->l_next;
    {
#if defined(DNLOAD_SAFE_SYMTAB_HANDLING)
      // Find symbol from link map. We need the string table and a corresponding symbol table.
      const char* strtab = (const char*)elf_get_library_dynamic_section(lmap, DT_STRTAB);
      const dnload_elf_sym_t *symtab = (const dnload_elf_sym_t*)elf_get_library_dynamic_section(lmap, DT_SYMTAB);
      const uint32_t* hashtable = (const uint32_t*)elf_get_library_dynamic_section(lmap, DT_HASH);
      unsigned dynsymcount;
      unsigned ii;
#if defined(__linux__)
      if(NULL == hashtable)
      {
        hashtable = (const uint32_t*)elf_get_library_dynamic_section(lmap, DT_GNU_HASH);
        // DT_GNU_HASH symbol counter borrows from FreeBSD rtld-elf implementation.
        dynsymcount = 0;
        {
          unsigned bucket_count = hashtable[0];
          const uint32_t* buckets = hashtable + 4 + ((sizeof(void*) / 4) * hashtable[2]);
          const uint32_t* chain_zero = buckets + bucket_count + hashtable[1];
          for(ii = 0; (ii < bucket_count); ++ii)
          {
            unsigned bkt = buckets[ii];
            if(bkt == 0)
            {
              continue;
            }
            {
              const uint32_t* hashval = chain_zero + bkt;
              do {
                ++dynsymcount;
              } while(0 == (*hashval++ & 1u));
            }
          }
        }
      }
      else
#endif
      {
        dynsymcount = hashtable[1];
      }
      for(ii = 0; (ii < dynsymcount); ++ii)
      {
        const dnload_elf_sym_t *sym = &symtab[ii];
#else
      // Assume DT_SYMTAB dynamic entry immediately follows DT_STRTAB dynamic entry.
      // Assume DT_STRTAB memory block immediately follows DT_SYMTAB dynamic entry.
      const dnload_elf_dyn_t *dynamic = elf_get_dynamic_element_by_tag(lmap->l_ld, DT_STRTAB);
      const char* strtab = (const char*)elf_transform_dynamic_address(lmap, (const void*)(dynamic->d_un.d_ptr));
      const dnload_elf_sym_t *sym = (const dnload_elf_sym_t*)elf_transform_dynamic_address(lmap, (const void*)((dynamic + 1)->d_un.d_ptr));
      for(; ((void*)sym < (void*)strtab); ++sym)
      {
#endif
        const char *name = strtab + sym->st_name;
#if defined(DNLOAD_SAFE_SYMTAB_HANDLING)
        // UND symbols have valid names but no value.
        if(!sym->st_value)
        {
          continue;
        }
#endif
        if(sdbm_hash((const uint8_t*)name) == hash)
        {
          //if(!sym->st_value)
          //{
          //  printf("incorrect symbol in library '%s': '%s'\n", lmap->l_name, name);
          //}
          return (void*)((const uint8_t*)sym->st_value + (size_t)lmap->l_addr);
        }
      }
    }
  }
}
/** \brief Perform init.
 *
 * Import by hash - style.
 */
static void dnload(void)
{
  unsigned ii;
  for(ii = 0; (15 > ii); ++ii)
  {
    void **iter = ((void**)&g_symbol_table) + ii;
    *iter = dnload_find_symbol(*(uint32_t*)iter);
  }
}
#endif

#if defined(__clang__)
/** Visibility declaration for symbols that require it (clang). */
#define DNLOAD_VISIBILITY __attribute__((visibility("default")))
#else
/** Visibility declaration for symbols that require it (gcc). */
#define DNLOAD_VISIBILITY __attribute__((externally_visible,visibility("default")))
#endif

#if !defined(USE_LD)
#if defined(__cplusplus)
extern "C" {
#endif
/** Program entry point. */
void _start() DNLOAD_VISIBILITY;
#if defined(__cplusplus)
}
#endif
#endif
#endif

